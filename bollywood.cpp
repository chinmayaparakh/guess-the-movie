#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

class film
{
private:
    string movie;
    char a[50];
public:
    film(){
        cout<<endl<<"For hint enter '.' "<<endl;
        read();
    }
    string read()
    {string line[100];
        int i=0;
        ifstream fp("movie.txt");

        while(getline(fp,line[i]))
        {

            i++;
        }

        return selection(line);
    }
    string selection(string line[])
    {
        srand(time(0));
        int i = (rand() % 100) + 1;
        movie = line[i];
        int n=movie.length();
        for(int j=0;j<n;j++)
{
    if(movie[j]==' ')
    {
        a[j]=' ';
    }
    else
        a[j]='-';
}
        return movie;
    }
    void print()
    {int n=movie.length();
    cout<<"Name of the movie: ";
    for(int i=0;i<n;i++)
        {
        cout<<a[i];
        }
        cout<<endl<<endl<<"____________________________________________"<<endl;
    }
int getletter()
{char let;
    cout<<endl<<"Letter: ";
    cin>>let;
    return let;
}

void chance(int a)
{
    cout<<endl<<"Chances Remaining: "<<10-a<<endl;
}

    void hint()
    {int n=movie.length();
    for(int j=0;j<n;j++)
        {
        if(a[j]=='-')
            {
                a[j]=movie[j];
                return;
            }
        }
    }
    void insertion(char b)
    {int n=movie.length();
        for(int j=0;j<n;j++)
        {

            if(movie[j]==b)
            {
                a[j]=b;
            }
        }
    }
    bool isCheck(char b)
    {int n=movie.length();
        for(int j=0;j<n;j++)
        {

        if(movie[j]==b)
            {
                a[j]=b;
                return 1;
            }
        }
        return 0;
    }

    bool isEqual()
    {int n=movie.length();
        for(int i=0;i<n;i++)
        {
            if(a[i]!=movie[i])
            {
                return 0;
            }
        }
        return 1;
    }

void gameplay()
{int k=0;
char letter;
    while(k!=10)
    {
        print();
        chance(k);
        letter = getletter();
        if(letter=='.')
        {
            hint();
            if(isEqual())
            {   print();
                cout<<"Congratulations!!! You won the game"<<endl;
                exit(0);
            }

        }
        if(isCheck(letter))
        {
            insertion(letter);
            if(isEqual())
            {   print();
                cout<<"Congratulations!!! You won the game"<<endl;
                exit(0);
            }
        }
        else
            k++;
    }
    cout<<endl<<"____________________________________________"<<endl;
    cout<<"You have exhausted your 10 moves"<<endl;
    cout<<"Game over"<<endl;
    cout<<"Name of the movie is "<<movie<<endl;

}
film(string a)
{
    film start;
    start.gameplay();
}


};

int main()
{
    film s("begin");

}
