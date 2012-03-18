#ifndef PARSECSV_H
#define PARSECSV_H
#include <assert.h>
#include <iterator>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
/*
std::vector<std::string> getNextLineAndSplitIntoTokens(std::istream& str)
{
    std::vector<std::string>   result;
    std::string                line;
    std::getline(str,line);

    std::stringstream          lineStream(line);
    std::string                cell;

    while(std::getline(lineStream,cell,','))
    {
        result.push_back(cell);
    }
    return result;
}
*/
class CVSRow
{
public:
    std::string const& operator[](std::size_t index) const
    {
        return m_data[index];
    }
    std::size_t size() const
    {
        return m_data.size();
    }
    void readNextRow(std::istream& str)
    {
        std::string         line;
        std::getline(str,line);

        std::stringstream   lineStream(line);
        std::string         cell;

        m_data.clear();
        while(std::getline(lineStream,cell,','))
        {
            m_data.push_back(cell);
        }
    }
private:
    std::vector<std::string>    m_data;
};


std::istream& operator>>(std::istream& str,CVSRow& data)
{
    data.readNextRow(str);
    return str;
}
class CVSIterator
{
public:

    CVSIterator(std::istream& str)  :m_str(str.good()?&str:NULL) { ++(*this); }
    CVSIterator()                   :m_str(NULL) {}

    // Pre Increment
    CVSIterator& operator++()               {if (m_str) { (*m_str) >> m_row;m_str = m_str->good()?m_str:NULL;}return *this;}
    // Post increment
    CVSIterator operator++(int)             {CVSIterator    tmp(*this);++(*this);return tmp;}
    CVSRow const& operator*()   const       {return m_row;}
    CVSRow const* operator->()  const       {return &m_row;}
    std::size_t size() const
    {
        return m_row.size();
    }

    bool operator==(CVSIterator const& rhs) {return ((this == &rhs) || ((this->m_str == NULL) && (rhs.m_str == NULL)));}
    bool operator!=(CVSIterator const& rhs) {return !((*this) == rhs);}
private:
    std::istream*       m_str;
    CVSRow              m_row;
};

std::vector< std::vector<std::string> > parseData(const char* filename){
    std::ifstream       file(filename);
    std::vector< std::vector<std::string> > values;
    int i = 0;
    for(CVSIterator loop(file);loop != CVSIterator();loop++)
    {
        std::vector<std::string> row;
        for(i = 0;i < (int)loop.size();i++){
            //std::cout << "1st Element(" << (*loop)[i] << ")\n";
            row.push_back((*loop)[i]);
        }
        values.push_back(row);
    }
    return values;
}

#endif // PARSECSV_H
