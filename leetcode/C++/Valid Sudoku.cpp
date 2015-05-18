// Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

// The Sudoku board could be partially filled, where empty cells are filled with the character '.'.


// A partially filled sudoku which is valid.
// Note:
// A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.

//只要数独合法即可，即每一行 每一列 每一个小方块内不能重复出现1~9
//可以没有解


class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool used[9];

        for(int i=0;i<9;i++)
        {
        	fill(used,used+9,false);
        	for(int j=0;j<9;j++) //row
        	{
        		if(check(board[i][j],used)==false)
        			return false
        	}

        	fill(used,used+9,false);
        	for(int j=0;j<9;j++) //col
        	{
        		if(check(board[j][i],used)==false)
        			return false;
        	}
        }

        for(int r=0;r<3;r++)
        {
        	for(int c=0;c<3;c++)
        	{
        		fill(used,used+9,false);
        		for(int i=r*3;i<r*3+3;i++)
        		{
        			for(int j=c*3;j<c*3+3;j++)
        				if(check(board[i][j],used)==false)
        					return false;
        		}
        	}
        }

        return true;
    }

    bool check(char ch,bool used[9])
    {
    	if(ch=='.') return true;

    	if(used[ch-'1']) return false;

    	return used[ch-'1']=true;

    }
};

// 就是遍历棋盘的所有位置，查看每一个位置上的元素是否满足Sudoku的要求，
// 也就是每一行，每一列以及每个小9×9的区域是否存在相同的元素，如果存在相同的元素，
// 即为不合法。对于判断一个元素是否在某一行，某一列或者某个小区域内，
// 我的实现是将定义了9个整数代表每一列，9个整数代表每一行，9个元素代表了9个小的9×9的区域
// 因此，用每一个整数的第1到第九位表示某个元素是否在该列，该行或该小区域中。
// 通过位操作可以判断该元素是否存在。


//============
bool isValidSudoku(vector<vector<char> > &board) {
        // Note: The Solution object is instantiated only once.
		int row[9],col[9];
		
		for(int i = 0; i < 9; i++)
		{
			memset(row,0,sizeof(int)*9);
			memset(col,0,sizeof(int)*9);
			for(int j = 0; j < 9; j++)
			{
				if(board[i][j] != '.')
				{
					if(row[board[i][j]-'1'] > 0)return false;
					else row[board[i][j]-'1']++;
				}
				if(board[j][i] != '.')
				{
					if(col[board[j][i]-'1'] > 0)return false;
					else col[board[j][i]-'1']++;
				}
			}
		}

		for(int i = 0; i < 9; i+=3)
			for(int j = 0; j < 9; j+=3)
			{
				memset(row,0,sizeof(int)*9);
				for(int a = 0; a < 3; a++)
					for(int b= 0; b < 3; b++)
						if(board[i+a][j+b] != '.')
						{
							if(row[board[i+a][j+b]-'1']>0)return false;
							else row[board[i+a][j+b]-'1']++;
						}
			}
        return true;
    }


 //

bool isValidSudoku(vector<vector<char> > &board) {
        // Note: The Solution object is instantiated only once.
		vector<vector<bool>> rows(9, vector<bool>(9,false));
		vector<vector<bool>> cols(9, vector<bool>(9,false));
		vector<vector<bool>> blocks(9, vector<bool>(9,false));

		for(int i = 0; i < 9; i++)
			for(int j = 0; j < 9; j++)
			{
				if(board[i][j] == '.')continue;
				int num = board[i][j] - '1';
				if(rows[i][num] || cols[j][num] || blocks[i - i%3 + j/3][num])
					return false;
				rows[i][num] = cols[j][num] = blocks[i - i%3 + j/3][num] = true;
			}
		return true;
    }


//



public boolean isValidSudoku(char[][] board) {
        // Start typing your Java solution below
        // DO NOT write main() function
       
        for(int i=0; i<board.length; i++){
            for(int j=0; j<board[0].length; j++){
                if(board[i][j]=='.')
                    continue;
                char tmp = board[i][j];
                board[i][j] = 'C';
                boolean tr = isValid(board, i, j, tmp);
                board[i][j] = tmp;
                if(tr == false)
                    return tr;
            }
        }
        return true;
    }
   
    public boolean isValid(char[][] board, int x, int y, char tmp){
        for(int i=0; i<9; i++){
            if(board[x][i] == tmp || board[i][y] == tmp)
                return false;
        }
       
        int start_x = x/3;
        int start_y = y/3;
        for(int i=0; i<9; i++){
            int cur_x = start_x*3 + i/3;
            int cur_y = start_y*3 + i%3;
            if(board[cur_x][cur_y] == tmp)
                return false;
        }
        return true;
    }


//

public boolean isValidSudoku(char[][] board) {
        // Start typing your Java solution below
        // DO NOT write main() function
        ArrayList<HashMap<Integer, Integer>> row_list_map = new ArrayList<HashMap<Integer, Integer>>();
        ArrayList<HashMap<Integer, Integer>> col_list_map = new ArrayList<HashMap<Integer, Integer>>();
        ArrayList<HashMap<Integer, Integer>> grid_list_map = new ArrayList<HashMap<Integer, Integer>>();
        for(int i=0 ;i<9; i++){
            HashMap<Integer, Integer> tmp = new HashMap<Integer, Integer>();
            row_list_map.add(tmp);
            tmp = new HashMap<Integer, Integer>();
            col_list_map.add(tmp);
            tmp = new HashMap<Integer, Integer>();
            grid_list_map.add(tmp);
        }   
   
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j] == '.')
                    continue;

                if(row_list_map.get(i).containsKey(board[i][j]-'0')){
                    return false;
                }else{
                    row_list_map.get(i).put(board[i][j]-'0', 1);
                }
               
                if(col_list_map.get(j).containsKey(board[i][j]-'0')){
                    return false;
                }else{
                    col_list_map.get(j).put(board[i][j]-'0', 1);
                }
               
                int index = ((i/3) * 3) + (j/3);
                if(grid_list_map.get(index).containsKey(board[i][j]-'0')){
                    return false;
                }else{
                    grid_list_map.get(index).put(board[i][j]-'0', 1);
                }
            }
        }
       
        return true;
   
    }


// 注意到题目中说的,只要当前已经填充的数字是合法的就可以,不一定要这个数独是有解.（下面说的九宫格都是指3*3的网格）

// 因此只需要判断9*9网格的每一行、每一列、9个小九宫格是否合法。即如果在每一行、每一列、每个9个小九宫格内，某个数字重复出现了，当前数独就是不合法的。本文地址

// 网上很多解法是：行、列、九宫格、分三个两重循环来分别判断是否合法。其实只需要一个两重循环即可

// 需要注意的是： 如果把九宫格按照行从0开始标号，那么数字board[i][j] 位于第 i/3*3+j/3 个九宫格内

class Solution {
public:
  bool isValidSudoku(vector<vector<char> > &board) {
    int rowValid[10] = {0};//用于判断某一行是否合法，对于行来说这个数组可以重复使用
    int columnValid[9][10] = {0};//用于判断某一列是否合法
    int subBoardValid[9][10] = {0};//用于判断某一个九宫格是否合法
    for(int i = 0; i < 9; i++)
    {
      memset(rowValid, 0, sizeof(rowValid));
      for(int j = 0; j < 9; j++)
        if(board[i][j] != '.')
        {
          if(!checkValid(rowValid, board[i][j]-'0') ||
             !checkValid(columnValid[j], board[i][j]-'0') ||
             !checkValid(subBoardValid[i/3*3+j/3], board[i][j]-'0'))
             return false;
        }
    }
    return true;
  }
  bool checkValid(int vec[], int val)
  {
    if(vec[val] == 1)return false;
    vec[val] = 1;
    return true;
  }
};

// 针对上面的算法，还可以优化空间。
// 上面的算法中，在双重循环时，我们默认了第一重循环表示矩阵的行、第二重循环表示矩阵的列。可以换一种思路：

// 在检测行是否合法时，i 表示矩阵的行，j 表示矩阵的列；
// 检测列是否合法时，i 表示矩阵的列，j 表示矩阵的行；
// 检测九宫格是否合法时，i 表示九宫格的标号，j 表示九宫格里的每个元素
// （只是我们需要根据i、j定位相应的元素到原来的矩阵：
//  第 i 个九宫格里面的第 j 个元素在原矩阵的第 3*(i/3) + j/3 行，第 3*(i%3) + j%3）列 ，
//  “/” 表示整数除法）
class Solution {
public:
  bool isValidSudoku(vector<vector<char> > &board) {
    int rowValid[10] = {0};//用于判断某一行是否合法
    int columnValid[10] = {0};//用于判断某一列是否合法
    int subBoardValid[10] = {0};//用于判断某一个九宫格是否合法
    for(int i = 0; i < 9; i++)
    {
      memset(rowValid, 0, sizeof(rowValid));
      memset(columnValid, 0, sizeof(columnValid));
      memset(subBoardValid, 0, sizeof(subBoardValid));
      for(int j = 0; j < 9; j++)
      {
          if(!checkValid(rowValid, board[i][j]-'0') ||
             !checkValid(columnValid, board[j][i]-'0') ||
             !checkValid(subBoardValid, board[3*(i/3) + j/3][3*(i%3) + j%3]-'0'))
             return false;
      }
    }
    return true;
  }
  bool checkValid(int vec[], int val)
  {
    if(val < 0)return true;//对应的是字符‘.’
    if(vec[val] == 1)return false;
    vec[val] = 1;
    return true;
  }
};

//这种类型的游戏一般回溯法来解决，设置某个空格时，如果该空格无论设置什么数字都无法达到合法状态，那么回溯重新设置上一个空格，详细见代码注释
class Solution {
public:
  void solveSudoku(vector<vector<char> > &board) {
    for(int i = 0; i < 9; i++)
      for(int j = 0; j < 9; j++)
        if(board[i][j] != '.')
          fill(i, j, board[i][j] - '0');
    solver(board, 0);
  }
  
  bool solver(vector<vector<char> > &board, int index)
  {// 0 <= index <= 80，index表示接下来要填充第index个格子
    if(index > 80)return true;
    int row = index / 9, col = index - 9*row;
    if(board[row][col] != '.')
      return solver(board, index+1);
    for(int val = '1'; val <= '9'; val++)//每个为填充的格子有9种可能的填充数字
    {
      if(isValid(row, col, val-'0'))
      {
        board[row][col] = val;
        fill(row, col, val-'0');
        if(solver(board, index+1))return true;
        clear(row, col, val-'0');
      }
    }
    board[row][col] = '.';//注意别忘了恢复board状态
    return false;
  }
  
  //判断在第row行col列填充数字val后，是否是合法的状态
  bool isValid(int row, int col, int val)
  {
    if(rowValid[row][val] == 0 &&
       columnValid[col][val] == 0 &&
       subBoardValid[row/3*3+col/3][val] == 0)
       return true;
    return false;
  }
  
  //更新填充状态
  void fill(int row, int col, int val)
  {
    rowValid[row][val] = 1;
    columnValid[col][val] = 1;
    subBoardValid[row/3*3+col/3][val] = 1;
  }
  
  //清除填充状态
  void clear(int row, int col, int val)
  {
    rowValid[row][val] = 0;
    columnValid[col][val] = 0;
    subBoardValid[row/3*3+col/3][val] = 0;
  }
private:
  int rowValid[9][10];//rowValid[i][j]表示第i行数字j是否已经使用
  int columnValid[9][10];//columnValid[i][j]表示第i列数字j是否已经使用
  int subBoardValid[9][10];//subBoardValid[i][j]表示第i个小格子内数字j是否已经使用
};




