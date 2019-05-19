#include <iostream>

// constant
const int COIN[] = { 100, 50, 25, 10, 5, 1 }; // the value of each coin
const int MAX_COIN_USE = 100; // the maximum number of coins to give in change 

// global variable and global array, to hold the best change combination
// will be updated if a new best combination (smallest number of coins used) is found
int best_coin_num = INT_MAX; // initialize with the maximum integer, this suggests there is no solution
int best_coin_used[MAX_COIN_USE]; // hold the best coin used
int solution_num = 0; // hold the total number of solutions. Will be updated when each solution is found 

void Change(int start_coin, int amount, int coin_used[], int num_coin_used);

int main()
{
  int coin_used[MAX_COIN_USE];
  int amount;
  
  // input the amount 
  std::cout << "Please input the amount: ";
  std::cin >> amount;
  
  // calculate 
  Change(0, amount, coin_used, 0);
  
  std::cout << "\nThere are " << solution_num << " combinations\n"
  << "The best combination is: ";
  for (int i = 0; i < best_coin_num; i++)
  {
    std::cout << best_coin_used[i] << " ";
  }
  std::cout << "\n";
  
  return 0;
}

void Change(int start_coin, int amount, int coin_used[], int num_coin_used)
{
  /* Base case */
  // 1-if there is no more coins to be used 
  // this happens when the function is trying to find out all combinations that don't use the first coin of the remaining coin set 
  // the coin set will decreased to zero, under this circumstance, there is no solution for this combination 
  // the temporary record of coin used will not be showed because it is not correct combination (no solution)
  if (start_coin == 6)
    return;
  
  // 2-if the amount is negative
  // this happens when the function is trying to find out all combinations that do use the first coin of the remaining coin set
  // to use the first coin means to subtract amount with the value of the first coin
  // if the result of amount - value_of_first_coin is negative, it means you can't use the first coin to change 
  // so, this way of combination is wrong, no solution 
  if (amount < 0)
    return;
  
  // 3-if the amount is exactly zero 
  // this means the amount in the immediate upper level is changed successfully
  // the record of coin used has been stored in the coin_used[] array, the size of coin-used[] is num_coin_used 
  // check if this combination is the best (whether the num_coin_used is lowest)
  // if this combination is the best, store into the best_coin_used[] and update best_coin_num
  // also, print out this combination
  // update solution number 
  if (amount == 0)
  {
    // update solution_num
    solution_num++;
    
    // print out the combination 
    std::cout << "Solution " << solution_num << ": ";
    for (int i = 0; i < num_coin_used; i++)
    {
      std::cout << coin_used[i] << " ";
    }
    std::cout << "\n";
    
    // check if it is the best result, if so, update the best container 
    if (num_coin_used < best_coin_num)
    {
      for (int i = 0; i < num_coin_used; i++)
        best_coin_used[i] = coin_used[i];
      
      best_coin_num = num_coin_used;
    }
    
    // return 
    return;
  }
  
  /* If no base case reached: calculate change recursively */
  // 1. Find out all combinations that change for the amount, using all but the first coin in the available coin set (combinations that do not use the first coin, which is Coin[start_coin])
  Change(start_coin + 1, amount, coin_used, num_coin_used);
  
  // 2. Find out all combinations that change for the amount, that do use the first coin in the available coin set. This is actually considered as the scenario that the first coin is used, and this usage should be recorded in coin_used[] array, the num_coin_used should be updated. Then the Change() function is called again to find out the actual combination (based on the fact that the number of combination of an amount changed with n - 1 coins is equal to the number of combinations to make change for the [amount - value_of_the_first_coin] using all n coins)
  
  // record coin being used 
  coin_used[num_coin_used] = COIN[start_coin];
  num_coin_used++;
  // calculate the number of combinations 
  Change(start_coin, amount - COIN[start_coin], coin_used, num_coin_used);
}