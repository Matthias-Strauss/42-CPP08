/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 14:15:49 by mstrauss          #+#    #+#             */
/*   Updated: 2025/04/08 13:18:09 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <iostream>

class Span {
private:
  int *_arr;
  unsigned int _size;
  unsigned int _count;

public:
  Span();
  Span(unsigned int N);
  Span(const Span &other);
  ~Span();

  Span &operator=(const Span &other);

  unsigned int size() const;
  unsigned int count() const;

  void addNumber();
  void shortestSpan();
  void longestSpan();

  class iterator {
  private:
    int *_ptr;

  public:
    iterator(int *ptr) : _ptr(ptr) {}

    int &operator*() const { return *_ptr; }
    int *operator->() const { return _ptr; }

    iterator &operator++() {
      ++_ptr;
      return *this;
    }

    iterator operator++(int) {
      iterator temp = *this;
      ++_ptr;
      return temp;
    }

    iterator &operator--() {
      --_ptr;
      return *this;
    }

    iterator operator--(int) {
      iterator temp = *this;
      --_ptr;
      return temp;
    }

    bool operator==(const iterator &other) const { return _ptr == other._ptr; }
    bool operator!=(const iterator &other) const { return _ptr != other._ptr; }
  };
};