/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 16:25:41 by mstrauss          #+#    #+#             */
/*   Updated: 2025/04/05 12:55:19 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T> int easyfind(T &container, int value) {
  typename T::iterator i = std::find(container.begin(), container.end(), value);
  if (i == container.end()) {
    throw std::runtime_error("Value not found in container");
  }
  return *i;
}
