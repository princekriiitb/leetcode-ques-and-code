class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int x1=rec1[0];
        int y1=rec1[1];
        int x2=rec1[2];
        int y2=rec1[3];

        int p1=rec2[0];
        int q1=rec2[1];
        int p2=rec2[2];
        int q2=rec2[3];

        if(p1>=x2||p2<=x1||q1>=y2||q2<=y1)
        return false;
        else
        return true;
    }
};