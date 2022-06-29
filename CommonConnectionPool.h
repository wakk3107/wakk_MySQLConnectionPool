#include"Connection.h"
#include<queue>
#include<mutex>
#include<thread>
#include<atomic>
#include<functional>
class ConnectionPool {
public:
	//��ȡ���ӳض���ʵ��
	static ConnectionPool* getConnectionPool();
	shared_ptr<Connection> getConnection();
	
private:
	bool loadConfigFile();
	//���������ӵ��̺߳���
	void produceConnectionTask();
	void scannerConnectionTask();
	ConnectionPool();//����1:���캯��˽�л�
	string _ip; // mysql��ip��ַ
	unsigned short _port; // mysql�Ķ˿ں� 3306
	string _username; // mysql��¼�û���
	string _password; // mysql��¼����
	string _dbname; // ���ӵ����ݿ�����
	int _initSize; // ���ӳصĳ�ʼ������
	int _maxSize; // ���ӳص����������
	int _maxIdleTime; // ���ӳ�������ʱ��
	int _connectionTimeout; // ���ӳػ�ȡ���ӵĳ�ʱʱ��

	queue<Connection*> _connectionQue; // �洢mysql���ӵĶ���
	mutex _queueMutex; // ά�����Ӷ��е��̰߳�ȫ������
	atomic_int _connectionCnt; // ��¼������������connection���ӵ������� 
	condition_variable cv; // ���������������������������̺߳����������̵߳�ͨ��
};

