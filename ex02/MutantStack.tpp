/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 16:41:09 by mstrauss          #+#    #+#             */
/*   Updated: 2025/04/11 15:19:29 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <class T, class Container>
MutantStack<T, Container>::MutantStack() : std::stack<T, Container>() {}

template <class T, class Container>
MutantStack<T, Container>::MutantStack(const MutantStack &other)
    : std::stack<T, Container>(other) {}

template <class T, class Container>
MutantStack<T, Container> &
MutantStack<T, Container>::operator=(const MutantStack &other) {
  if (this != &other) {
    std::stack<T, Container>::operator=(other);
  }
  return *this;
}

template <class T, class Container> MutantStack<T, Container>::~MutantStack() {}

template <class T, class Container>
typename MutantStack<T, Container>::iterator
MutantStack<T, Container>::begin() {
  return this->c.begin();
}

template <class T, class Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::end() {
  return this->c.end();
}