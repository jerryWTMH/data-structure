F94041026 徐慶航
這份作業主要是希望能讓tree裡面的element刪掉，然後還是可以保持max heap該有的結構。

typedef struct stack{}:主要是宣告新的struct名叫stack。
int combine(char a,char b){}:主要是結合兩個個位數的char變成十位數的int，特別用來處理十位數~

int main(){
	char input[30]:初始化。
	fgets(input):收資料。
	for{ }:主要是儲存fgets收取進來的string裡面不是空白鍵位置的資料到st1(我令的stack)裡面，
	       其中裡面還有判斷數字是十位數以及個位數的處理辦法。(int stack_counter是用來記新讀出的數值應塞入st1的哪個位置)(int counter主要是判斷是否是十位數的參數)。
	
	char input2[30]:初始化。
	fgets(input2):收資料。
	for{}:主要是得到需刪掉的數值。

	int change_position:需刪掉的element的位置。
	int change_position2:從children中遞補上去的element位置。
	for{}:主要是把最後一個element的數值存進欲刪除element的位置，並且讓最後一個element的值變為0。
	
	for{}:主要檢查是否符合max_heap，其中的判斷式主要是選擇其element的較大的children進行數值上的交換，達到max heap的結構。
	
	for{}:print出st1的內容。
}
