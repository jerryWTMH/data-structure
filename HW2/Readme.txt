F94041026 ��u108 �}�y��

���Y�ɤ���
#include <iomanip> :�x�}�ƪ��C	
#include <time.h>  :�f�tsrand(time(NULL));�i�H���C����rand()�����@�˪����G�C

�ܼƤ���
int result1[15][15]; //�Ĥ@�p�D��result�x�}
int result2[39][19]; //�ĤG�p�D��result�x�}
int k;int m;		 //k�Mm�����ѼƦr���ܼ�
int imove[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };
int jmove[8] = { 1, 1, 1, 0, -1, -1, -1, 0 };
int position1[2] = { 10,10 }; //�Ĥ@�p�D����e(x,y)
int position2[2] = { 1,1 };   //�ĤG�p�D����e(x,y)
int check1(int result1[15][15])   //�P�_�Ĥ@�p�D�O�_����
int count1 = 0; //�Ĥ@�p�D����B�ƪ�l��
int count2 = 0; //�ĤG�p�D�����B�ƪ�l��

Function����
int check1()//�P�_�Ĥ@�p�D�O�_�����A�̭��|�i��for���B��Ӭݥ������y�г����Q���L�@���C
int check2()//�P�_�ĤG�p�D�O�_�����A�P�W�C

int main()����
�{�������c�D�n�O�p�U:
����_�l�I�B�Ƴ]��1 => ��l�ƥ���B�� => �]�Ȧs�ܼ�position11�Ӧs���ʫe���y�� => while�j��A����O�I�sfunction�ӬݬO�_�n�~�� =>
�j�餺�D�n�O����e���y�жi�沾�ʦA�i��P�w�C�p�G���ʧ���W�X�d��Y�ը��@�B�A��Ȧs�ܼƪ��Ȧs�^��e���y�СC�p�G���ʧ���èS���W�X�y��
�A�N���s���y�Ц�m���p�ƾ�+1�åB����B�ƥ[1�C

P.S. 127��᪺���ѱ������쥻�|���N���{���X�A�O�����|�索�W����ɡB�k�W����ɡB�k�U����ɡB�k�W����ɡB������ɡB�W����ɡB�k����ɡB�U�����
���K�ثD�嫬��m�i�檽������V����A����T�O�C�@�B���X�h���@�w���b�ɽu�H�����A���L�P�D�N�B�M�A�]���D�ت��e�D���]�N�O�����U��V���v�@�ˡC�̷�
�ڪ��g�k�|�ܦ��U��V���v�����o�@�ˡC
