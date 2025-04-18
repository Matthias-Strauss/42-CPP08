/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 14:15:47 by mstrauss          #+#    #+#             */
/*   Updated: 2025/04/18 20:11:56 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <limits>
#include <numeric>

Span::Span() : _arr(nullptr), _size(0), _amount(0) {}

Span::Span(unsigned int N) : _size(N), _amount(0) { _arr = new int[_size]; }

Span::Span(const Span &other) : _size(other._size), _amount(other._amount)
{
  _arr = new int[_size];
  for (unsigned int i = 0; i < _amount; ++i)
  {
    _arr[i] = other._arr[i];
  }
}

Span::~Span() { delete[] _arr; }

Span &Span::operator=(const Span &other)
{
  if (this != &other)
  {
    delete[] _arr;
    _size = other._size;
    _amount = other._amount;
    _arr = new int[_size];
    for (unsigned int i = 0; i < _amount; ++i)
    {
      _arr[i] = other._arr[i];
    }
  }
  return *this;
}

unsigned int Span::size() const { return _size; }

unsigned int Span::count() const { return _amount; }

void Span::addNumber(int num)
{
  if (_amount == _size)
  {
    throw std::runtime_error("Span is full");
  }
  _arr[_amount] = num;
  _amount++;
}

void Span::shortestSpan() const
{
  if (_amount < 2)
  {
    throw std::runtime_error("Insufficient amount of numbers to find a span");
  }

  std::vector<int> sortedArr(_arr, _arr + _amount);
  std::sort(sortedArr.begin(), sortedArr.end());

  int minSpan = std::numeric_limits<int>::max();
  for (size_t i = 0; i < sortedArr.size() - 1; ++i)
  {
    int span = sortedArr[i + 1] - sortedArr[i];
    if (span < minSpan)
    {
      minSpan = span;
    }
  }
  std::cout << "Shortest span: " << minSpan << std::endl;
}

void Span::longestSpan() const
{
  if (_amount < 2)
  {
    throw std::runtime_error("Insufficient amount of numbers to find a span");
  }
  std::vector<int> sortedArr(_arr, _arr + _amount);
  std::sort(sortedArr.begin(), sortedArr.end());

  int maxSpan = sortedArr.back() - sortedArr.front();
  std::cout << "Longest span: " << maxSpan << std::endl;
}
