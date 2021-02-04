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

    Level(int w)
    {
        words=w;
        srand(time(NULL));
        for(int i=0; i<words; i++)
        {
            wpos[i] = {rand()%47+2, rand()%22+2}; //2 to 47 and 2 to 22
            tpos[i] = {rand()%47+2, rand()%22+2};
//            wpos[i] = {rand()%(48+1-2)+2, rand()%(23+1-2)+2};
//            tpos[i] = {rand()%(48+1-2)+2, rand()%(23+1)-2)+2};
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
            for (int col=0; col<width; col++)
            {
                if (col==ppos.x && row==ppos.y)
                    cout<<"P";
                else if(row==0 || row==24 )
                    cout<<"-";
                else if(col==0 || col==49)
                    cout<<"|";
                else
                {
                    f=0;
                    for(int i=0; i<tpos.size(); i++)
                    {
                        if(col==wpos[i].x && row==wpos[i].y)
                        {
                            f=1;
                            cout<<"W";
                        }
                        else if(col==tpos[i].x && row==tpos[i].y)
                        {
                            f=1;
                            cout<<"w";
                        }
                    }
                    if(f==0)
                        cout<<".";
                }

            }
            cout<<"\n";
        }
    }
};

//struct position
//{
//    int px, py;
//    int wx1,wx2,wx3,wx4,wx5,wx6,wx7,wx8,wx9,wx10;
//    int wy1,wy2,wy3,wy4,wy5,wy6,wy7,wy8,wy9,wy10;
//    int tx1,tx2,tx3,tx4,ty1,ty2,ty3,ty4;
//};
//
//struct grid
//{
//    int width, height;
//
//    void Render(position pos)
//    {
//        for (int row=0; row<height; row++)
//        {
//            for (int col=0; col<width; col++)
//            {
//                if (col==pos.px && row==pos.py)
//                {
//                    printf("P");
//                }
//
//                else if(col==pos.wx1 && row==pos.wy1 || col==pos.wx2 && row==pos.wy2 || col==pos.wx3 && row==pos.wy3 || col==pos.wx4 && row==pos.wy4)
//                {
//                    cout<<"W";
//                }
//                else if(level==2 && (col==pos.wx5 && row==pos.wy5 || col==pos.wx6 && row==pos.wy6))
//                {
//                    cout<<"W";
//                }
//                else if(grid_flag[row][col]!=1 && (col==pos.tx1 && row==pos.ty1 || col==pos.tx2 && row==pos.ty2 || col==pos.tx3 && row==pos.ty3 || col==pos.tx4 && row==pos.ty4))
//                {
//                    cout<<"w";
//                }
//                else if(row==0 || row==24 )
//                {
//                    cout<<"-";
//                }
//
//                else if(col==0 || col==49)
//                {
//                    cout<<"|";
//                }
//
//                else
//                {
//                    cout<<".";
//                }
//            }
//
//            printf("\n");
//        }
//    }
//};

#endif // GRID_H_INCLUDED
