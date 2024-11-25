#include <SFML/Graphics.hpp>
#include <iostream>
#include <thread>

#include "project-button.h"

using namespace std;
using namespace sf;

const int GENERATE_DATA_SIZE = 40;

enum class SortingAlgorithm
{
    BUBBLE_SORT,
    SELECTION_SORT,
    INSERTION_SORT,
    MERGE_SORT,
    QUICK_SORT
};

class SortingVisualizer
{
private:
    RenderWindow window;
    vector<int> data;
    thread sortingThread;
    bool isSorting = false;
    SortingAlgorithm currentAlgorithm = SortingAlgorithm::BUBBLE_SORT;
    Font font;
    vector<Button> buttons;
    bool isPaused = false;

    void generateData(size_t size)
    {
        data.clear();
        for (size_t i = 0; i < size; ++i)
        {
            data.push_back(rand() % (window.getSize().y - 150));
        }
    }

    void bubbleSort()
    {
        for (size_t i = 0; i < data.size() - 1; ++i)
        {
            for (size_t j = 0; j < data.size() - i - 1; ++j)
            {
                if (data[j] > data[j + 1])
                {
                    swap(data[j], data[j + 1]);
                    visualize();
                }
            }
        }
    }

    void selectionSort()
    {
        for (size_t i = 0; i < data.size() - 1; ++i)
        {
            size_t minIndex = i;
            for (size_t j = i + 1; j < data.size(); ++j)
            {
                if (data[j] < data[minIndex])
                {
                    minIndex = j;
                }
            }
            if (minIndex != i)
            {
                swap(data[i], data[minIndex]);
                visualize();
            }
        }
    }

    void insertionSort()
    {
        for (size_t i = 1; i < data.size(); ++i)
        {
            int key = data[i];
            int j = i - 1;
            while (j >= 0 && data[j] > key)
            {
                data[j + 1] = data[j];
                --j;
                visualize();
            }
            data[j + 1] = key;
        }
    }

    void mergeSort(size_t left, size_t right)
    {
        if (left < right)
        {
            size_t mid = left + (right - left) / 2;
            mergeSort(left, mid);
            mergeSort(mid + 1, right);
            merge(left, mid, right);
        }
    }

    void merge(size_t left, size_t mid, size_t right)
    {
        vector<int> temp(right - left + 1);
        size_t i = left, j = mid + 1, k = 0;

        while (i <= mid && j <= right)
        {
            if (data[i] <= data[j])
            {
                temp[k++] = data[i++];
            }
            else
            {
                temp[k++] = data[j++];
            }
        }

        while (i <= mid)
            temp[k++] = data[i++];
        while (j <= right)
            temp[k++] = data[j++];

        for (size_t m = 0; m < temp.size(); ++m)
        {
            data[left + m] = temp[m];
            visualize();
        }
    }

    void quickSort(size_t low, size_t high)
    {
        if (low < high)
        {
            size_t pivot = partition(low, high);
            if (pivot > 0)
                quickSort(low, pivot - 1);
            quickSort(pivot + 1, high);
        }
    }

    size_t partition(size_t low, size_t high)
    {
        int pivot = data[high];
        size_t i = low;

        for (size_t j = low; j < high; ++j)
        {
            if (data[j] <= pivot)
            {
                swap(data[i], data[j]);
                visualize();
                ++i;
            }
        }
        swap(data[i], data[high]);
        visualize();
        return i;
    }

    void togglePause()
    {
        isPaused = !isPaused;
    }

    void visualize()
    {
        window.clear(Color::Black);

        float barWidth = (window.getSize().x - 40.0f) / data.size();

        for (size_t i = 0; i < data.size(); ++i)
        {
            RectangleShape bar(Vector2f(barWidth - 1, data[i]));
            bar.setPosition(i * barWidth + 20, window.getSize().y - data[i]);
            bar.setFillColor(Color(240, 193, 7));
            window.draw(bar);
        }

        for (auto &button : buttons)
        {
            button.draw(window);
        }

        window.display();
        sleep(milliseconds(20));
    }

    void handleEvents()
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                if (sortingThread.joinable())
                    sortingThread.join();
                window.close();
            }

            if (event.type == Event::MouseButtonPressed)
            {
                if (!isSorting)
                {
                    for (auto &button : buttons)
                    {
                        if (button.isClicked(Mouse::getPosition(window)))
                        {
                            button.onClick();
                            generateData(GENERATE_DATA_SIZE);
                            break;
                        }
                    }
                }
            }

            if (event.type == Event::KeyPressed && event.key.code == Keyboard::Enter || event.key.code == Keyboard::Space && !isSorting)
            {
                if (sortingThread.joinable())
                    sortingThread.join();

                isSorting = true;
                sortingThread = thread([this]()
                                       {
                    switch (currentAlgorithm)
                    {
                    case SortingAlgorithm::BUBBLE_SORT:
                        bubbleSort();
                        break;
                    case SortingAlgorithm::SELECTION_SORT:
                        selectionSort();
                        break;
                    case SortingAlgorithm::INSERTION_SORT:
                        insertionSort();
                        break;
                    case SortingAlgorithm::MERGE_SORT:
                        mergeSort(0, data.size() - 1);
                        break;
                    case SortingAlgorithm::QUICK_SORT:
                        quickSort(0, data.size() - 1);
                        break;
                    }
                    isSorting = false; });

                generateData(GENERATE_DATA_SIZE);
            }

            if (event.type == Event::KeyPressed && event.key.code == Keyboard::R && !isSorting)
            {

                togglePause();
            }
        }
    }

public:
    SortingVisualizer() : window(VideoMode(800, 600), "Sorting Visualizer")
    {
        if (!font.loadFromFile("/System/Library/Fonts/Supplemental/Arial.ttf"))
        {
            cerr << "Failed to load font!" << endl;
        }

        buttons.emplace_back(Vector2f(200, 60), Vector2f(10, 10), Color(255, 255, 255), Color(0, 0, 0), "Bubble Sort", font, [this]()
                             { setActiveButton(SortingAlgorithm::BUBBLE_SORT); });

        buttons[0].setClickedFillColor();
        buttons[0].setClickedTextColor();

        buttons.emplace_back(Vector2f(200, 60), Vector2f(220, 10), Color(255, 255, 255), Color(0, 0, 0), "Selection Sort", font, [this]()
                             { setActiveButton(SortingAlgorithm::SELECTION_SORT); });
        buttons.emplace_back(Vector2f(200, 60), Vector2f(440, 10), Color(255, 255, 255), Color(0, 0, 0), "Insertion Sort", font, [this]()
                             { setActiveButton(SortingAlgorithm::INSERTION_SORT); });
        buttons.emplace_back(Vector2f(200, 60), Vector2f(660, 10), Color(255, 255, 255), Color(0, 0, 0), "Merge Sort", font, [this]()
                             { setActiveButton(SortingAlgorithm::MERGE_SORT); });
        buttons.emplace_back(Vector2f(200, 60), Vector2f(880, 10), Color(255, 255, 255), Color(0, 0, 0), "Quick Sort", font, [this]()
                             { setActiveButton(SortingAlgorithm::QUICK_SORT); });
        generateData(GENERATE_DATA_SIZE);
        window.setFramerateLimit(60);
    }

    void setActiveButton(SortingAlgorithm algorithm)
    {

        for (auto &button : buttons)
        {
            button.setDefaultFillColor();
            button.setDefaultTextColor();
        }

        currentAlgorithm = algorithm;
        updateButtonColor();
    }

    void updateButtonColor()
    {
        switch (currentAlgorithm)
        {
        case SortingAlgorithm::BUBBLE_SORT:
            buttons[0].setClickedFillColor();
            buttons[0].setClickedTextColor();
            break;
        case SortingAlgorithm::SELECTION_SORT:
            buttons[1].setClickedFillColor();
            buttons[1].setClickedTextColor();
            break;
        case SortingAlgorithm::INSERTION_SORT:
            buttons[2].setClickedFillColor();
            buttons[2].setClickedTextColor();
            break;
        case SortingAlgorithm::MERGE_SORT:
            buttons[3].setClickedFillColor();
            buttons[3].setClickedTextColor();
            break;
        case SortingAlgorithm::QUICK_SORT:
            buttons[4].setClickedFillColor();
            buttons[4].setClickedTextColor();
            break;
        }
    }

    ~SortingVisualizer()
    {
        if (sortingThread.joinable())
            sortingThread.join();
    }

    void run()
    {
        while (window.isOpen())
        {
            handleEvents();
            if (!isSorting && !isPaused)
            {
                visualize();
            }
        }
    }

    RenderWindow &getWindow() { return window; }
};

template <typename T, typename... Args>
std::unique_ptr<T> make_unique(Args &&...args)
{
    return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}
