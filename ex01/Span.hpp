/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 14:15:49 by mstrauss          #+#    #+#             */
/*   Updated: 2025/04/11 13:58:20 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <vector>

class Span {
private:
  int *_arr;
  unsigned int _size;
  unsigned int _amount;

public:
  Span();
  Span(unsigned int N);
  Span(const Span &other);
  ~Span();

  Span &operator=(const Span &other);

  unsigned int size() const;
  unsigned int count() const;

  void addNumber(int num);
  template <typename Iterator> void addNumber(Iterator begin, Iterator end);
  void shortestSpan() const;
  void longestSpan() const;
};

#include "Span.tpp"
#endif