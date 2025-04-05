/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 14:15:49 by mstrauss          #+#    #+#             */
/*   Updated: 2025/04/05 14:27:55 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <iostream>

class Span {
private:
  int *_arr;
  unsigned int _size;

public:
  Span();
  Span(unsigned int N);
  Span(const Span &other);
  ~Span();

  Span &operator=(const Span &other);

  unsigned int size() const;

  void addNumber();
  void shortestSpan();
  void longestSpan();
};