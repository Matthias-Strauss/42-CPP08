/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 16:24:14 by mstrauss          #+#    #+#             */
/*   Updated: 2025/04/05 14:12:12 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <list>
#include <vector>

int main(void) {
  std::vector<int> vec;
  vec.push_back(10);
  vec.push_back(20);
  vec.push_back(30);

  std::list<int> lst;
  lst.push_back(5);
  lst.push_back(15);
  lst.push_back(25);

  try {
    std::vector<int>::iterator i = easyfind(vec, 20);
    std::cout << "Vector: Finding 20: " << &*i << std::endl;
    std::cout << "Vector: Finding 5: ";
    easyfind(vec, 5);
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }

  try {
    std::list<int>::iterator i = easyfind(lst, 15);
    std::cout << "List: Finding 15: " << &*i << std::endl;
    std::cout << "List: Finding 30: ";
    easyfind(lst, 30);
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }

  return 0;
}
