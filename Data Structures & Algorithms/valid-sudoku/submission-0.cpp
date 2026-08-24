class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> rows[9];
        unordered_set<char> cols[9];
        unordered_set<char> boxes[9];

        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                char current_val = board[i][j];
                if(current_val == '.'){
                    continue;
                }
                //check if the element is already in same row
                if(rows[i].find(current_val) != rows[i].end()) {return false;}
                if(cols[j].find(current_val) != cols[j].end()) {return false;}
                int box_index = (i / 3) * 3 + (j / 3);
                if(boxes[box_index].find(current_val) != boxes[box_index].end()) {return false;}

                rows[i].insert(current_val);
                cols[j].insert(current_val);
                boxes[box_index].insert(current_val);
            }
        }
        return true;
    }
};
