// #include<iostream>
// #include<vector>
// #include<algorithm>
// using namespace std;

// struct Item{
//     double value;
//     double weight;
// };

// bool cmp(Item a, Item b){
//     double r1 = a.value / a.weight;
//     double r2 = b.value / b.weight;
//     return r1 > r2;
// }

// double fractionalKnapsack(int n, double W, vector<Item> &items){
//     sort(items.begin(),items.end(),cmp);

//     double totalValue = 0.0;

//     for(int i=0;i<n;i++){
//         if(items[i].weight <= W){
//             W -= items[i].weight;
//             totalValue += items[i].value;
//         }
//         else{
//             totalValue += items[i].value * (W / items[i].weight);
//             break;
//         }
//     }
//     return totalValue;
// }

// int main(){
//     int n;
//     double W;
//     cout<<"Enter number of items: ";
//     cin>>n;
//     vector<Item> items(n);

//     cout<<"Enter value and weight of each item:"<<endl;
//     for(int i=0;i<n;i++){
//         cin>>items[i].value >> items[i].weight;
//     }

//     cout<<"Enter capacity of knapsack: ";
//     cin>>W;

//     double maxValue = fractionalKnapsack(n, W, items);
//     cout<<"Maximum value in the knapsack = "<<maxValue<<endl;
//     return 0;
// }

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Item{
    double value;
    double weight;
};

bool cmp(Item a, Item b){
    double r1 = a.value / a.weight;
    double r2 = b.value / b.weight;
    return r1 > r2;
}

double fractionalKnapsack(int n, double W, vector<Item>& items){
    sort(items.begin(),items.end(),cmp);

    double totalValue = 0.0;

    for(int i=0;i<n;i++){
        if(items[i].weight <= W){
            W -= items[i].weight;
            totalValue += items[i].value;
        }
        else{
            totalValue += items[i].value * (W / items[i].weight);
            break;
        }
    }
    
    return totalValue;
}

int main(){
    int n;
    double W;
    cout<<"Enter number of items: ";
    cin>>n;
    vector<Item> items(n);

    cout<<"Enter value and weight of each item: "<<endl;
    for(int i=0;i<n;i++){
        cin>>items[i].value >> items[i].weight;
    }

    cout<<"Enter capacity of knapsack: ";
    cin>>W;

    double maxValue = fractionalKnapsack(n,W,items);
    cout<<"Maximum value in the knapsack = "<<maxValue<<endl;
}