/********************************************************************************************************
*                                   Who Turned out the Lights
*                                   Written and Documented by:
*                                       Mathew Jackson
*
*            DESCRIPTION:
*            Given a size for a row, this program will generate a series of zeros and ones where
*            0's represent an OFF light and a 1's represents an ON light.
*
*            Implementation requires the use of recursion to "backtrack" the given row to find a
*            solution which will be printing out the corresponding button pushes based on the index.
*
*            If a button is pushed, than that button will become its opposite (1 becomes 0, and 0 becomes 1)
*            while making all adjacent indexes opposite to what they are.
*
*            The goal of the game is to make all indexes 0.
*
*
*
*
*            TODO: COMPLETE

                    FIXED: button assignment array and console out
*                           Error Check
*
*
*
**********************************************************************************************************/
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;
// Prototypes

void lightsOut(int[], int[], bool, int);
void fillArray(int[], int); // random array generator
// Counters
int i = 0;
int n = 0;

int main()
{
    bool quit = false;;
    int arraySize;
    cout<<"\t\t\t\tWELCOME TO LIGHTS OUT!"<<endl;
    cout<<"\t\t\t\t Single row edition\n\n"<<endl;
    cout << "Enter number of cells: ";
    cin>>arraySize;

    string inputProblem;
    int lightsArray[arraySize];
    int buttonsPushed[arraySize];


    cout<<"Please enter your problem. \n*Note: Extra digits that were not accounted for in the size prompt will be cut off"<<endl;
    cin>>inputProblem;

        for(int i = 0; i < arraySize; i++){ // set all buttons to -1 for POST-check
            buttonsPushed[i] = -1;
        }

       // fillArray(lightsArray, arraySize); // Randomly make a series of 0's and 1's
        for(int i = 0; i < arraySize; i++){ // manually add numbers
            lightsArray[i] = inputProblem[i] - '0';
        }
        // Pre-solved
        for(int i = 0; i < arraySize; i++){
            cout<<lightsArray[i];
        }
        n = 0; // reset buttonsPushed[] index
        lightsOut(lightsArray, buttonsPushed, false, arraySize); // check if there is a solution
        // Post-solved: FOR ERROR CHECKING ONLY
        /*cout<<"\n";
        for(int i = 0; i < arraySize; i++){
            cout<<lightsArray[i];
        }
        */
        cout<<"\n";
        if(lightsArray[arraySize - 1] == 1 || lightsArray[arraySize - 2] == 1){
            cout<<"\nNO SOLUTION"<<endl;
        }
        else{
            for(int i = 0; i < arraySize; i++){
                    if(buttonsPushed[i] == -1){

                    }
                    else{
                        cout<<buttonsPushed[i]<<" ";
                    }
            }
        }

    return 0;
}
void fillArray(int Array[], int size){ // randomly set an array based on how many elements the user decided to use
    srand(time(NULL));

    if(size == 0){
        return;
    }
    for(int j = 0; j < size; j++){
        Array[j] = rand() % 2;
    }
}
void lightsOut(int Array[],int buttonsPushed[], bool change, int size){

    if(size == 0){ // fail if array is size 0
        return;
    }
    if(change){ // if a recursive call was made with a change parameter of true
        buttonsPushed[n] = i + 1;
        n++;

        if(Array[i] == 0){
            Array[i] = 1;
            if(i + 1 < size){
                if(Array[i + 1] == 0){
                    Array[i + 1] = 1;
                }else{
                    Array[i + 1] = 0;
                }
            }
        }else{
            Array[i] = 0;
            if(i + 1 < size){
                if(Array[i + 1] == 0){
                    Array[i + 1] = 1;
                }else{
                    Array[i + 1] = 0;
                }
            }
        }
    }
    if(Array[i] == 1){ // Light is on
            if(i + 1 == size){ // check to see if the next index is out of bounds
                    if(size == 1){ // special case: if the size is 1
                        buttonsPushed[n] = i + 1; // add to the buttons pressed array, add 1 to offset array index starting at zero
                        n++;
                        Array[i] = 0;
                        return;
                    }
                    if(change){ // if this instance of the function has gone through a change already
                        return;
                    }
                    if(size % 2 == 0){
                        Array[i] = 0;
                        Array[i - 1] = 1;
                    }

                Array[i] = 0;

                return;
            }else{
                //buttonsPushed[n] = i + 1;
                //                                      `                                                                                                                                                                                                                           n++;
                Array[i] = 0;
                i++;
                lightsOut(Array,buttonsPushed, true, size);
            }
    }
    else{
        if(i + 1 < size){
            i++;
            lightsOut(Array,buttonsPushed, false, size);
        }else{
            if(size == 1){
                buttonsPushed[n] = i + 1;
                Array[i] = 1;
                n++;
            }
            if(!change){
                return;
            }
            else{
                Array[i] = 0;
                return;
            }
        }

    }
}
