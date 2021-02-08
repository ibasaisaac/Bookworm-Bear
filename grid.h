#ifndef GRID_H_INCLUDED
#define GRID_H_INCLUDED

using namespace std;

struct position
{
    int x, y;
};

struct Level
{
    int words;
    map<int, position>wpos, tpos;

    Level(int w) //member function
    {
        words=w;
        srand(time(NULL));
        for(int i=0; i<words; i++)
        {
            wpos[i] = {rand()%(28+1-2)+2, rand()%(13+1-2)+2}; //(max +1 -min)+min
            tpos[i] = {rand()%(28+1-2)+2, rand()%(13+1-2)+2};
        }
    }
};

struct grid
{
    int width, height, f=0;

    void Render(position ppos, map<int, position> wpos, map<int, position> tpos)
    {
        for (int row=0; row<height; row++)
        {
            cout<<"\t\t      ";
            for (int col=0; col<width; col++)
            {
                if(row==0 || row==height-1)
                {
                    SetColor(darkgray);
                    cout<<"-";
                    SetColor(white);
                }
                else if(col==0 || col==width-1)
                {
                    SetColor(darkgray);
                    cout<<"|";
                    SetColor(white);
                }
                else if (col==ppos.x && row==ppos.y)
                {
                    cout<<"P";
                }
                else
                {
                    f=0;
                    for(unsigned int i=0; i<wpos.size(); i++)
                    {
                        if(col==wpos[i].x && row==wpos[i].y)
                        {
                            f=1;
                            cout<<"W";
                            break;
                        }
                    }
                    if(f==0)
                    {
                        for(unsigned int i=0; i<tpos.size(); i++)
                        {
                            if(col==tpos[i].x && row==tpos[i].y)
                            {
                                f=1;
                                cout<<"w";
                                break;
                            }
                        }
                    }
                    if(f==0)
                    {
                        SetColor(darkgray);
                        cout<<".";
                        SetColor(white);
                    }
                }
            }
            cout<<"\n";
        }
    }
};

#endif // GRID_H_INCLUDED
