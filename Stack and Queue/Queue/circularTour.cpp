//function to calculate the starting point for a truck in a circular path where n petrol pumps are present so that truck can complete the circle without exhausting its petrol

//class of petrolPump
class petrolPump{
    int petrol;
    int distance; //distance from that petrol pump to next petrol pump
};

int startPoint(petrolPump p[], int n){

    int balance = 0; //to keep account of remaining petrol
    int start = 0; //to mark the start position
    int deficit = 0; //to keep account of deficit petrol

    for(int i=0; i<n; i++){

        balance += p[i].petrol - p[i].distance;
        if(balance < 0){
            deficit += balance;
            balance = 0;
            start = i+1;
        }
    }

    if(balance + deficit >= 0) return start;
    else return -1;
}