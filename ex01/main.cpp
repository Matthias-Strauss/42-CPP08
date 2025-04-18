/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 16:24:14 by mstrauss          #+#    #+#             */
/*   Updated: 2025/04/18 20:11:02 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <array>
#include <iostream>
#include <vector>

int main()
{

  std::cout << std::endl;
  std::cout << "####################################" << std::endl;
  std::cout << "Test 1: Basic test with a small Span" << std::endl;
  std::cout << "####################################" << std::endl;

  std::cout << "Creating Span with size 5." << std::endl;
  Span sp = Span(5);

  std::cout << "Adding number: 5" << std::endl;
  sp.addNumber(5);
  std::cout << "Adding number: 17" << std::endl;
  sp.addNumber(17);
  std::cout << "Adding number: 9" << std::endl;
  sp.addNumber(9);
  std::cout << "Adding number: 11" << std::endl;
  sp.addNumber(11);
  std::cout << "Getting shortest span using shortestSpan(): ";
  sp.shortestSpan();
  std::cout << "Getting longest span using longestSpan(): ";
  sp.longestSpan();
  std::cout << std::endl;

  std::cout << std::endl;
  std::cout << "######################################" << std::endl;
  std::cout << "Test 2: Adding numbers using iterators" << std::endl;
  std::cout << "######################################" << std::endl;
  std::cout << "Creating empty Span with size 10 ..." << std::endl;
  Span sp2 = Span(10);
  std::cout
      << "Creating std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}"
      << std::endl;
  std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::cout << "Copying values from the vector to the Span using "
               "Span.addNumber(it.begin(), it.end())"
            << std::endl;
  sp2.addNumber(nums.begin(), nums.end());
  std::cout << "Getting Shortest span: ";
  sp2.shortestSpan();
  std::cout << "Gettings Longest span: ";
  sp2.longestSpan();
  std::cout << std::endl;

  std::cout << std::endl;
  std::cout << "####################################" << std::endl;
  std::cout << "Test 3: Adding numbers from an array" << std::endl;
  std::cout << "####################################" << std::endl;
  std::cout << "Creating empty Span with size 5 ..." << std::endl;
  Span sp3 = Span(5);
  std::cout << "Creating int arr[] = {50, 20, 30, 40, 10}" << std::endl;
  int arr[] = {50, 20, 30, 40, 10};
  std::cout << "Calling Span.addNumber(arr, arr + 5)" << std::endl;
  sp3.addNumber(arr, arr + 5);
  std::cout << "Getting Shortest span: ";
  sp3.shortestSpan();
  std::cout << "Getting Longest span: ";
  sp3.longestSpan();
  std::cout << std::endl;

  std::cout << std::endl;
  std::cout << "###################################" << std::endl;
  std::cout << "Test 4: Exception when Span is full" << std::endl;
  std::cout << "###################################" << std::endl;
  std::cout << "Creating empty Span with size 3 ..." << std::endl;
  Span sp4 = Span(3);
  std::cout << "Calling Span.addNumber(1)" << std::endl;
  sp4.addNumber(1);
  std::cout << "Calling Span.addNumber(2)" << std::endl;
  sp4.addNumber(2);
  std::cout << "Calling Span.addNumber(3)" << std::endl;
  sp4.addNumber(3);
  std::cout << "Triggering exception by calling Span.addNumber(3) while Span "
               "is already full."
            << std::endl;
  try
  {
    sp4.addNumber(4);
  }
  catch (const std::exception &e)
  {
    std::cerr << "Exception: " << e.what() << std::endl;
  }
  std::cout << std::endl;

  std::cout << std::endl;
  std::cout << "###############################################################"
               "##################"
            << std::endl;
  std::cout << "Test 5: Exception when shortestSpan/longestSpan is called with "
               "less than 2 numbers"
            << std::endl;
  std::cout << "###############################################################"
               "##################"
            << std::endl;
  std::cout << "Creating empty Span with size 1 ..." << std::endl;
  Span sp5 = Span(1);
  std::cout << "Calling Span.addNumber(1)" << std::endl;
  sp5.addNumber(1);
  std::cout << "Triggering exception by calling Span.shortestSpan() while Span "
               "contains insufficient elements."
            << std::endl;
  try
  {
    sp5.shortestSpan();
  }
  catch (const std::exception &e)
  {
    std::cerr << "Exception: " << e.what() << std::endl;
  }
  std::cout << "Triggering exception by calling Span.longestSpan() while Span "
               "contains insufficient elements."
            << std::endl;
  try
  {
    sp5.longestSpan();
  }
  catch (const std::exception &e)
  {
    std::cerr << "Exception: " << e.what() << std::endl;
  }
  std::cout << std::endl;

  std::cout << std::endl;
  std::cout << "#######################" << std::endl;
  std::cout << "Test 6: Large Span test" << std::endl;
  std::cout << "#######################" << std::endl;
  std::cout << "Creating empty Span with size 10000 ..." << std::endl;
  Span sp6 = Span(10000);
  std::cout << "Creating vector<int> with size 10000 ..." << std::endl;
  std::vector<int> largeNums(10000);
  std::cout << "Filling Vector with 10000 ascending numbers ..." << std::endl;
  for (int i = 0; i < 10000; ++i)
  {
    largeNums[i] = i;
  }
  std::cout << "Copying all values from Vector to Span using "
               "Span.addNumber(vec.begin(), vec.end()) (using iterators)"
            << std::endl;
  sp6.addNumber(largeNums.begin(), largeNums.end());
  std::cout << "Getting shortest span using shortestSpan(): ";
  sp6.shortestSpan();
  std::cout << "Getting longest span using longestSpan(): ";
  sp6.longestSpan();
  std::cout << std::endl;

  return 0;
}

// DEPRECATED

// Adding from a non-int container should fail at compile time
// std::cout << std::endl;
// std::cout << "###############################################################"
//              "#######"
//           << std::endl;
// std::cout
//     << "Test 7: Adding from a non-int container (should fail at compile time)"
//     << std::endl;
// std::cout << "###############################################################"
//              "#######"
//           << std::endl;
// std::cout << "Creating empty Span of size 5 ...";
// Span sp7 = Span(5);
// std::cout << "Creating vector<double> invalids = {1.1, 2.2, 3.3, 4.4, 5.5}"
//           << std::endl;
// std::vector<double> invalids = {1.1, 2.2, 3.3, 4.4, 5.5};
// std::cout << "UNCOMMENT IN MAIN.CPP TO SEE COMPILATION ERROR WHEN TRYING TO "
//              "ADD NON INTS TO SPAN!"
//           << std::endl;
// sp7.addNumber(invalids.begin(), invalids.end()); // This should not compile
// std::cout << std::endl;