/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 16:41:04 by mstrauss          #+#    #+#             */
/*   Updated: 2025/04/11 15:12:36 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP
#include <algorithm>
#include <deque>
#include <iostream>
#include <stack>

template <class T, class Container = std::deque<T>>

class MutantStack : public std::stack<T, Container> {
public:
  MutantStack();
  MutantStack(const MutantStack &other);
  MutantStack &operator=(const MutantStack &other);
  ~MutantStack();

  typedef typename std::stack<T, Container>::container_type::iterator iterator;

  iterator begin();
  iterator end();

private:
};

#include "MutantStack.tpp";
#endif
