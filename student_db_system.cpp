// ----------------------------------------------------OOP ASSINGMENT------------------------------------------------
//kavishka Gamage


#include<iostream>
#include<fstream>
#include<string>
#include<cmath>
#include<iomanip>

using namespace std;

const int MAXSUBJECTS = 10;
const int MAXSTUDENTS = 100;


class Subject{
    
    private:
        string subjCode;
        int noOfStu;

    public:
        int avgMark;

        Subject(){   //default constructor

        }

        Subject(string code,int noS){          //constructor
           
            subjCode = code;
            noOfStu = noS;
        }
        
        ~Subject(){    //destructor
        	
		}

        int marks[100];
        char grades[100];
        string student[100];

        int getnoStu(){
            return noOfStu;
        }

        string getCode(){
            return subjCode;
        }

        char calGrade(int x );
        float calAvgMark(int mark[]);             
        int* noOfGrades(char grades[],int n);
        
        //friend void  dispaly(Subject s);


};

	char Subject :: calGrade(int x){
		
			char grade;

            if(x<30 ){
                grade ='F';
            }
            else if(x<40){
                grade = 'D';
            }
            else if(x<55){
                grade = 'C';

            }
            else if(x<70){
                grade = 'B';
            }
            else{
                grade ='A';
            }

            return grade;
	
	}
	
	float  Subject :: calAvgMark(int mark[]){     

            int total =0;

            for(int i=0;i<noOfStu;i++){
                total += mark[i];
            }
            return total/noOfStu;
        }
        
    int*  Subject :: noOfGrades(char grades[],int n){
           
           
           int* total = new int[5];
           
           for(int i=0 ; i<5;i++)
                total[i] =0;

            for(int i=0;i<n;i++){

                if(grades[i] == 'A'){
                    total[0]+=1;
                }
                else if(grades[i] == 'B'){
                    total[1]+=1;
                }
                else if(grades[i] == 'C'){
                    total[2]+=1;
                }
                else if(grades[i] == 'D'){
                    total[3]+=1;
                }
                else if(grades[i] == 'F'){
                    total[4]+=1;
                }
            }
            
            return total;
            
        }  


void dispalySubject(Subject subj[],int currlen){               // option 1

    int flag =0;
    string code;
    printf("\nEnter  the subject code  : ");
    cin >> code;

    for(int i=0;i<currlen;i++){
        
        if(subj[i].getCode() ==  code ){

            flag =1;
            cout << "\nStudentId    Mark   Grade\n" << endl;

            for(int j=0;j<subj[i].getnoStu();j++){

                cout <<  subj[i].student[j] << "     " << subj[i].marks[j] << "     " << subj[i].grades[j] << endl;
            }
            break;
        }
    }

    if(flag == 0){                                     // print error message
        printf("\n !!!  Invalid subject code");
    }
}

void displayStudent(Subject subj[],int currlen){          //option 2

    int flag =0;
    string stuId;
    cout << "\nEnter student id : ";
    cin >> stuId;
    cout <<endl;
    cout << " Subject" << "    " << "Mark" << "    " << "Grade" << endl;

    for(int i=0;i<currlen;i++){

        for(int j=0;j<subj[i].getnoStu();j++){

            if(subj[i].student[j] == stuId){

                flag = 1;
                cout << subj[i].getCode()  << "     " << subj[i].marks[j]  << "    " << subj[i].grades[j] << endl;
                cout << subj[i].getCode()  << "     " << subj[i].marks[j]  << "    " << subj[i].grades[j] << endl;
            }
        }
    }
    if(flag == 0){
        cout << "\nInvalid student ID " << endl;
    }
}

void displaySummary(Subject subj[],int currlen){          //option 3


    int flag =0;
    string code;
    cout << "\n\nEnter the subject code : ";
    cin >> code; 
    int *total;
    float variance =0.0;
    float standardD;
    for(int i=0;i<currlen;i++){
        
        if(subj[i].getCode() ==  code ){

            flag =1;

            float avg = subj[i].calAvgMark(subj[i].marks);
            cout << "Average Mark       : " << avg << endl;

            total = subj[i].noOfGrades(subj[i].grades,subj[i].getnoStu());

            for(int j=0;j<currlen;j++){               //find standard deviation
                variance  += pow(subj[i].marks[j] - avg,2);
            }
            cout << "Standard deviation : "  << sqrt(variance/currlen) << endl;

            cout << "\nGrade       NoOfGrades  " << endl;

            cout << "A           " << total[0] << endl;
            cout << "B           " << total[1] << endl;
            cout << "C           " << total[2] << endl;
            cout << "D           " << total[3] << endl;
            cout << "F           " << total[4] << endl;
            break;
        }
    }
    if(flag == 0){                                     // print error message
        printf("\n !!!  Invalid subject code");
    }
}

void saveSummary(Subject subj[],int currlen){        //option 4
    
    int  n;
    int* total;
    
    ofstream fsum("summdata.txt");
    
    if(fsum.is_open()){

        for(int i=0;i<currlen;i++){

            n= subj[i].getnoStu();
            total = subj[i].noOfGrades(subj[i].grades,n);
            fsum << subj[i].getCode() << " " << n << " A " <<setprecision(1) << fixed <<  (total[0]/(float)n)*100 << "% B " << (total[1]/(float)n)*100 << "% C " << (total[2]/(float)n)*100 << "% D " << (total[3]/(float)n)*100 << "% F " << (total[4]/(float)n)*100 << "%" << endl;

        }    
        fsum.close();
        printf("\n Saved summary");
    }

    else{
            
        printf("\n couldn't save summary");
    }
}


int main(){

    int i = -1 , j ;
    Subject subj[10];   // create an array of object
    string line;
    
    ifstream fsubj("subjdata.txt");

    if(fsubj.is_open()){                    //check whether file can open or not 
                    
        printf("file opened\n");
        string word1;
        int word2;
        int len;

        while(fsubj >> word1 >> word2){

                len = log10(word2) + 1;

                if(word1.length() == 7 && (len <=3 && len >=0 )){   //checking data is whether correct or not
    
                    i++;
                    j=0;
                    subj[i] = Subject(word1,word2);      //using consturctor
                }

                else if (word1.length() == 8 && (len <=3 && len >=0 )){

                    subj[i].student[j] = word1 ;     // char 8
                    subj[i].marks[j] = word2 ;      //char 3
                    subj[i].grades[j] = subj[i].calGrade(word2);               //find grade and store it
                    j++;
                }
        }
    }

    else{
        printf("\nerror opening subject.txt file");
    }

    fsubj.close();
    int currlen = i+1;
    
   
// print options
    int opt ;
    do{

        printf("\n\n-----------------MENUE------------------\n\n");
        printf(" 1.Display subject\n 2.Display Student\n 3.Display Subject Summary\n 4.save Summaries\n 5.Exit program\n");
        printf("\n Enter an option - ");
       // cin >> opt ;
        scanf("%d",&opt);

        switch(opt){

            case 1:
                printf("\n      SUBJECT    \n");
                dispalySubject(subj,currlen);
                break;

            case 2:
                 printf("\n     STUDENT    \n");
                 displayStudent(subj,currlen);
                 break;

            case 3:
                printf("\n       SUMMARY   \n");
                displaySummary(subj,currlen);
                break;

            case 4:
                saveSummary(subj,currlen);
                break;

            case 5:
                exit(0);

            default :
                cout << "\nInvalid option" << endl;
                break;
        }
    }while(opt < 5  && opt>0);

    return 0;
}


