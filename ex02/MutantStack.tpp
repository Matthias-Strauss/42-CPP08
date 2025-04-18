/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 16:41:09 by mstrauss          #+#    #+#             */
/*   Updated: 2025/04/18 21:02:01 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template <class T, class Container>
MutantStack<T, Container>::MutantStack() : std::stack<T, Container>() {}

template <class T, class Container>
MutantStack<T, Container>::MutantStack(const MutantStack &other)
    : std::stack<T, Container>(other) {}

template <class T, class Container>
MutantStack<T, Container> &
MutantStack<T, Container>::operator=(const MutantStack &other)
{
  if (this != &other)
  {
    std::stack<T, Container>::operator=(other);
  }
  return *this;
}

template <class T, class Container>
MutantStack<T, Container>::~MutantStack() {}

template <class T, class Container>
typename MutantStack<T, Container>::iterator
MutantStack<T, Container>::begin()
{
  return this->c.begin();
}

template <class T, class Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::end()
{
  return this->c.end();
}

template <typename T>
void printStack(T &stack, const std::string &name)
{
  std::cout << name << " (" << stack.size() << " elements): ";
  if (stack.empty())
  {
    std::cout << "[empty]" << std::endl;
    return;
  }
  typename T::iterator it = stack.begin();
  typename T::iterator ite = stack.end();
  while (it != ite)
  {
    std::cout << *it << " ";
    ++it;
  }
  std::cout << "(top is " << stack.top() << ")" << std::endl;
}