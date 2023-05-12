#include <stdio.h>

int main() {

    int i, j;

    int party_votes[26];
    int party_seats[26];

    char letters[26];

    int number_of_partys; 
    int total_seat_number;
    
    float curr_max;
    int curr_maxs_index;
    
    int curr_seat_number = 0;

    float temp_calculation;

    char temp_char;
    int temp;

    scanf("%d %d", &number_of_partys, &total_seat_number);
    
    for(i = 0; i < number_of_partys; i++){
        
        scanf("%d", &party_votes[i]);

    }

    for(i = 0; i < number_of_partys; i++){
        
        party_seats[i] = 1;

    }

    for (i = 0; i < number_of_partys; i++) {
        letters[i] = 'A' + i;
    }

    while(curr_seat_number < total_seat_number){

        curr_max = party_votes[0]/(float)party_seats[0];  
        curr_maxs_index = 0;

        for(i = 0; i < number_of_partys; i++){

            temp_calculation = ( party_votes[i]/(float)party_seats[i] );

            if(temp_calculation > curr_max){

                curr_max = temp_calculation;
                curr_maxs_index = i;

            }

            else if(temp_calculation == curr_max){

                if(party_votes[i] > party_votes[curr_maxs_index]){

                    curr_max = temp_calculation;
                    curr_maxs_index = i;

                }

            }

        }

        party_seats[curr_maxs_index]++;
        curr_seat_number++;

    }
    
    for (i = 0; i < number_of_partys - 1; i++) {
        
        for (j = 0; j < number_of_partys - 1 - i; j++) {
            
            if (party_seats[j] < party_seats[j + 1]) {
                
                temp = party_seats[j];
                party_seats[j] = party_seats[j + 1];
                party_seats[j + 1] = temp;

                temp_char = letters[j];
                letters[j] = letters[j + 1];
                letters[j + 1] = temp_char;

            }
        }
    }

    for(i = 0; i < number_of_partys; i++){

        if(party_seats[i] == 1){
            /* No need to do anything */
        }

        else{

            printf("%c: %d\n", letters[i], party_seats[i]-1);

        }
    }
    
    return 0;
}
