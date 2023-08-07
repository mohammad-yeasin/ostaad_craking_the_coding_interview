#include <iostream>
#include <vector>


int stockPrediction(std::vector<int>& prices)
{
 int buy = prices[0];
 int sell = 0;
 
     for(int i = 1; i < prices.size(); i++)
     {
         if(prices[i] > buy && prices[i] >= sell) {
            sell = prices[i];   
         }
         else if(prices[i] < buy){
             buy = prices[i];
             sell = 0; //resetting the sell as we are buying
         }
     }
 
 if(sell == 0) return 0;
 else return sell - buy;
}

int main() {
    /*
    tested using 
    7,1,5,3,6,4 => 5
    7,6,4,3,1 => 0
    8,2,5,6,9,2,1,6,8,4,2,4,6,8,3,2 => 7
    */ 
    std::vector<int> vect{ 8,2,5,6,9,2,1,6,8,4,2,4,6,8,3,2 };
    std::cout << stockPrediction(vect);

    return 0;
}
