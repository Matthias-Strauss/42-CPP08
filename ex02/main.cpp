/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 16:24:14 by mstrauss          #+#    #+#             */
/*   Updated: 2025/04/18 20:59:15 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>

int main(void)
{
  {

    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
    std::cout << "~~~~~~~~~~~ Test ~~~~~~~~~" << std::endl;
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
    std::cout << std::endl;

    std::list<int> mstack;

    mstack.push_back(5);
    mstack.push_back(17);

    std::cout << mstack.back() << std::endl;

    mstack.pop_back();

    std::cout << mstack.size() << std::endl;

    mstack.push_back(3);
    mstack.push_back(5);
    mstack.push_back(737);
    //[...]
    mstack.push_back(0);

    std::list<int>::iterator it = mstack.begin();
    std::list<int>::iterator ite = mstack.end();

    ++it;
    --it;

    while (it != ite)
    {
      std::cout << *it << std::endl;
      ++it;
    }
    std::stack<int, std::list<int>> s(mstack);
  }

  std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;

  {
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << mstack.top() << std::endl;

    mstack.pop();

    std::cout << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it;
    --it;

    while (it != ite)
    {
      std::cout << *it << std::endl;
      ++it;
    }
    std::stack<int> s(mstack);
  }

  std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
  std::cout << "~~~~ Additional Tests ~~~~" << std::endl;
  std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
  std::cout << std::endl;

  {
    std::cout << "--- Test 1: Empty Stack ---" << std::endl;
    {
      MutantStack<float> emptyStack;
      std::cout << "Is empty? " << (emptyStack.empty() ? "Yes" : "No") << std::endl;
      std::cout << "Size: " << emptyStack.size() << std::endl;
      std::cout << "begin() == end()? " << (emptyStack.begin() == emptyStack.end() ? "Yes" : "No") << std::endl;
      printStack(emptyStack, "emptyStack");
    }
    std::cout << std::endl;

    std::cout << "--- Test 2: Copy Constructor ---" << std::endl;
    {
      MutantStack<int> originalStack;
      originalStack.push(10);
      originalStack.push(20);
      originalStack.push(30);
      printStack(originalStack, "originalStack");

      MutantStack<int> copiedStack(originalStack);
      printStack(copiedStack, "copiedStack");

      std::cout << "Modifying originalStack (push 40)..." << std::endl;
      originalStack.push(40);
      printStack(originalStack, "originalStack after mod");
      printStack(copiedStack, "copiedStack should be unchanged");

      std::cout << "Modifying copiedStack (pop)..." << std::endl;
      copiedStack.pop(); // pop 30
      printStack(originalStack, "originalStack should be unchanged");
      printStack(copiedStack, "copiedStack after mod");
    }
    std::cout << std::endl;

    std::cout << "--- Test 3: Assignment Operator ---" << std::endl;
    {
      MutantStack<std::string> stack1;
      stack1.push("Hello");
      stack1.push("World");
      printStack(stack1, "stack1");

      MutantStack<std::string> stack2;
      stack2.push("Foo");
      stack2.push("Bar");
      stack2.push("Baz");
      printStack(stack2, "stack2 (before assignment)");

      std::cout << "Assigning stack1 to stack2 (stack2 = stack1)..." << std::endl;
      stack2 = stack1;
      printStack(stack1, "stack1 after assignment");
      printStack(stack2, "stack2 after assignment");

      std::cout << "Modifying stack1 (push \"!\")..." << std::endl;
      stack1.push("!");
      printStack(stack1, "stack1 after mod");
      printStack(stack2, "stack2 should be unchanged");
    }
    std::cout << std::endl;

    std::cout << "--- Test 4: Iteration after Pushes/Pops ---" << std::endl;
    {
      MutantStack<int> mstack;
      mstack.push(1);
      mstack.push(2);
      mstack.pop();
      mstack.push(3);
      mstack.push(4);
      mstack.push(5);
      mstack.pop();
      printStack(mstack, "mstack after ops");
    }
    std::cout << std::endl;

    std::cout << "--- Test 5: Using std::find ---" << std::endl;
    {
      MutantStack<int> mstack;
      mstack.push(100);
      mstack.push(200);
      mstack.push(300);
      mstack.push(400);
      mstack.push(500);
      printStack(mstack, "mstack for find");

      int value_to_find = 300;
      MutantStack<int>::iterator found_it = std::find(mstack.begin(), mstack.end(), value_to_find);

      if (found_it != mstack.end())
      {
        std::cout << "Found " << value_to_find << " at iterator position. Value: " << *found_it << std::endl;
      }
      else
      {
        std::cout << value_to_find << " not found." << std::endl;
      }

      value_to_find = 999;
      found_it = std::find(mstack.begin(), mstack.end(), value_to_find);

      if (found_it != mstack.end())
      {
        std::cout << "Found " << value_to_find << " at iterator position. Value: " << *found_it << std::endl;
      }
      else
      {
        std::cout << value_to_find << " not found." << std::endl;
      }
    }
    std::cout << std::endl;

    std::cout << "--- Test 6: Modifying Element via Iterator ---" << std::endl;
    {
      MutantStack<int> mstack;
      mstack.push(11);
      mstack.push(22);
      mstack.push(33);
      printStack(mstack, "mstack before mod");

      MutantStack<int>::iterator it = mstack.begin();
      if (it != mstack.end())
      {
        std::cout << "Modifying element pointed to by begin() (value " << *it << ") to 99..." << std::endl;
        *it = 99;
      }
      printStack(mstack, "mstack after mod");

      it = mstack.begin();
      ++it;
      if (it != mstack.end())
      {
        std::cout << "Modifying element pointed to by begin()+1 (value " << *it << ") to 88..." << std::endl;
        *it = 88;
      }
      printStack(mstack, "mstack after 2nd mod");
    }
    std::cout << std::endl;
  }
}