/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 14:15:47 by mstrauss          #+#    #+#             */
/*   Updated: 2025/04/08 13:05:36 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _arr(nullptr), _size(0), _count(0) {}

Span::Span(unsigned int N) : _arr(new int[N]()), _size(N), _count(0) {}

Span::Span(const Span &other) : _arr(nullptr), _size(0) { *this = other; }

Span::~Span() {
  if (_arr != nullptr) {
    delete[] _arr;
    _arr = nullptr;
  }
}

Span &Span::operator=(const Span &other) {
  if (this != &other) {
    delete[] _arr;
    _size = other._size;
    _arr = new int[_size];
    _count = other._count;
    for (unsigned int i = 0; i < _count; ++i) {
      _arr[i] = other._arr[i];
    }
  }
  return *this;
}

unsigned int Span::size() const { return _size; }

void Span::addNumber() {}
void Span::shortestSpan() {}
void Span::longestSpan() {}
