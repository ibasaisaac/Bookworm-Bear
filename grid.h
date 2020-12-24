#ifndef GRID_H_INCLUDED
#define GRID_H_INCLUDED
using namespace std;
struct position
{
    int px, py;
    int wx1,wx2,wx3,wx4;
    int wy1,wy2,wy3,wy4;
};
struct grid
{
    int width, height;

    void Render(position pos)
    {
        for (int row=0; row<height; row++)
        {
            for (int col=0; col<width; col++)
            {
                if (col==pos.px && row==pos.py)
                {
                    printf("P");
                }

                else if(col==pos.wx1 && row==pos.wy1 || col==pos.wx2 && row==pos.wy2 || col==pos.wx3 && row==pos.wy3 || col==pos.wx4 && row==pos.wy4)
                {
                    cout<<"W";
                }

                else
                {
                    cout<<".";
                }
            }

            printf("\n");
        }
    }
};

#endif // GRID_H_INCLUDED
