F94041026 徐慶航
這次的作業是希望我們可以替換掉不要的element，並且使整體的tree可以隨element的變化而自動更動。

typedef struct stack{}:主要是宣告新的struct名叫stack。
int combine(char a,char b){}:主要是結合兩個個位數的char變成十位數的int，特別用來處理十位數~

int main(){
	char input[30]:初始化。
	fgets(input):收資料。
	for{ }:主要是儲存fgets收取進來的string裡面不是空白鍵位置的資料到st1(我令的stack)裡面，
	       其中裡面還有判斷數字是十位數以及個位數的處理辦法。(int stack_counter是用來記新讀出的數值應塞入st1的哪個位置)(int counter主要是判斷是否是十位數的參數)。
	   
	char input2[30]:初始化。
	fgets(input2):收資料。
	int change1:用來記錄應替換的原始值 int change2:用來記錄應替換的替換值。
	for{}:讀取原始值與替換值。
	
        int change_position:用來記錄替換的位置。
	for{}:找到change1在st1中的位置，並替換掉數值。

	if {}這邊的判斷是主要是用來換順序，會往parents的地方去看看是不是新更換的children比parents大。
	else if{}這是判斷children沒有比parents大的時候，假如children往下比發現比他自己的children還小時所會有的替換情形。

	for{}:print out出st1的結果。
}