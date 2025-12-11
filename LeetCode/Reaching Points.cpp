//Link: https://leetcode.com/problems/reaching-points/
class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        if(tx>ty)
        {
            swap(sx,sy);
            swap(tx,ty);
        }
        int a=tx, b=ty, mr;
        while(a>=sx&&b>=sy)
        {
            if(sx==a&&sy==b)
                return 1;
            if(a<b)
            {
                mr=(b/a)-(sy/a);
                b-=a*mr;
                if(mr==0)
                    break;
            }
            else
            {
                mr=(a/b)-(sx/b);
                if(mr==0)
                    break;
                a-=b*mr;
            }
        } 
        return 0;
    }
};
