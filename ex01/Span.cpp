/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 14:15:47 by mstrauss          #+#    #+#             */
/*   Updated: 2025/04/08 13:32:08 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <limits>
#include <numeric>

Span::Span() : _size(0) {}

Span::Span(unsigned int N) : _arr(N), _size(N) {}

Span::Span(const Span &other) : _arr(other._arr), _size(other._size) {}

Span::~Span() {}

Span &Span::operator=(const Span &other) {
  if (this != &other) {
    _arr = other._arr;
    _size = other._size;
  }
  return *this;
}

unsigned int Span::size() const { return _size; }

unsigned int Span::count() const { return _arr.size(); }

void Span::addNumber(int num) {
  if (_arr.size() == _size) {
    throw std::runtime_error("Span is full");
  }
  _arr.push_back(num);
}

void Span::shortestSpan() const {
  if (_arr.size() < 2) {
    throw std::runtime_error("Insufficient amount of numbers to find a span");
  }

  std::vector<int> sortedArr = _arr;
  std::sort(sortedArr.begin(), sortedArr.end());

  int minSpan = std::numeric_limits<int>::max();
  for (size_t i = 0; i < sortedArr.size() - 1; ++i) {
    int span = sortedArr[i + 1] - sortedArr[i];
    if (span < minSpan) {
      minSpan = span;
    }
  }
  std::cout << "Shortest span: " << minSpan << std::endl;
}

void Span::longestSpan() const {
  if (_arr.size() < 2) {
    throw std::runtime_error("Insufficient amount of numbers to find a span");
  }
  std::vector<int> sortedArr = _arr;
  std::sort(sortedArr.begin(), sortedArr.end());

  int maxSpan = sortedArr.back() - sortedArr.front();
  std::cout << "Longest span: " << maxSpan << std::endl;
}
