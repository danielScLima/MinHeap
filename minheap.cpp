#include "minheap.h"
#include <math.h>
#include <string>

MinHeap::MinHeap()
{
    numbers.push_back(-1); //Fake position
}

MinHeap::~MinHeap()
{
    numbers.clear();
}

int MinHeap::getNumberOfElementsInTheVector()
{
    return numbers.size()-1;
}

std::vector<int> MinHeap::getHeapAsAVector()
{
    std::vector<int> numbers2(numbers);
    numbers2.erase(numbers2.begin()+0);
    return numbers2;
}

int MinHeap::realToVirtual(int realPosition)
{
    return realPosition - 1;
}

int MinHeap::virtualToReal(int virtualPosition)
{
    return virtualPosition + 1;
}

void MinHeap::insertInterface(int number)
{
    int position = insert(number);
    upsideCheckAndMove(position);
}

int MinHeap::insert(int number)
{
    int size = this->numbers.size();
    this->numbers.push_back(number);
    return size;
}

void MinHeap::upsideCheckAndMove(int realPos)
{
    int tmpRealPos = realPos;
    while (tmpRealPos > 1)
    {
        int fatherRealPosition = getFatherRealPosition(tmpRealPos);
        if (fatherRealPosition < 1)
            return;
        if (this->numbers.at(fatherRealPosition) > this->numbers.at(tmpRealPos))
        {
            int temp = numbers[fatherRealPosition];
            numbers[fatherRealPosition] = numbers[tmpRealPos];
            numbers[tmpRealPos] = temp;

            tmpRealPos = fatherRealPosition;
        }
        else
            return;
    }
}

int MinHeap::leftChildRealPos(int realPosition)
{
    return 2 * realPosition;
}

int MinHeap::rightChildRealPos(int realPosition)
{
    return 2 * realPosition + 1;
}

int MinHeap::getFatherRealPosition(int realPosition)
{
    return floor(realPosition / 2);
}

const std::string MinHeap::gitDotFileMode1()
{
    std::string textToFile = "digraph g{";
    textToFile += "Root[shape=none fontcolor=blue];";

    if (numbers.size() == 1) //just fake number
    {
        textToFile += "NULL [ fontcolor=red ];Root -> NULL;";
    }
    else
    {
        for (int index = 1; index < numbers.size(); ++index)
        {
            textToFile += std::to_string(numbers[index])+";";
        }
        for (int index = 1; index < numbers.size(); ++index)
        {
            int leftChildRealPoNumber = leftChildRealPos(index);

            if (leftChildRealPoNumber < numbers.size())
            {
                textToFile += std::to_string(numbers[index])+"->"+
                        std::to_string(numbers[leftChildRealPoNumber])+";";
            }

            int rightChildRealPoNumber = rightChildRealPos(index);
            if (rightChildRealPoNumber < numbers.size())
            {
                textToFile += std::to_string(numbers[index])+"->"+
                        std::to_string(numbers[rightChildRealPoNumber])+";";
            }
        }
        textToFile += "Root->"+std::to_string(numbers[1])+";";
    }

    textToFile += "}";

    return textToFile;
}

int MinHeap::removeTheSmallerNumber()
{
    int swap = 0;
    int size = numbers.size();
    if (size <= 1) return -1;

    int removedNumber = numbers[1];
    numbers[1] = numbers.back();

    numbers.pop_back(); //remove o ultimo elemento

    size = numbers.size(); //atualiza o tamanho

    int index = 1;
    int smallerChildPos = 0;
    int rightChildPos = 0;
    while (index < size)
    {
        //verifica qual dos dois filhos é o menor
        smallerChildPos = leftChildRealPos(index);
        rightChildPos =rightChildRealPos(index);

        if (smallerChildPos < size && rightChildPos < size)
        {
            if (numbers[smallerChildPos] > numbers[rightChildPos])
                smallerChildPos = rightChildPos;

            //Verifica se deve fazer a troca
            if (numbers[index] > numbers[smallerChildPos])
            {
                swap = numbers[index];
                numbers[index] = numbers[smallerChildPos];
                numbers[smallerChildPos] = swap;

                index = smallerChildPos;
            }
            else
                break;
        }
        else if (smallerChildPos < size)
        {
            //Verifica se deve fazer a troca
            if (numbers[index] > numbers[smallerChildPos])
            {
                swap = numbers[index];
                numbers[index] = numbers[smallerChildPos];
                numbers[smallerChildPos] = swap;

                index = smallerChildPos;
            }
            else
                break;
        }
        else
            break; //Não precisa continuar
    }

    return removedNumber;
}
