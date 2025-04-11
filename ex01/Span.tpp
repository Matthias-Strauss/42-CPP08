/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:03:01 by mstrauss          #+#    #+#             */
/*   Updated: 2025/04/11 13:58:20 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename Iterator>
void Span::addNumber(Iterator begin, Iterator end) {
  static_assert(
      std::is_convertible<typename std::iterator_traits<Iterator>::value_type,
                          int>::value,
      "Type of iterator is not convertible to int");
  for (Iterator it = begin; it != end; ++it) {
    if (_amount == _size) {
      throw std::runtime_error("Span is full");
    }
    _arr[_amount] = *it;
    _amount++;
  }
}
