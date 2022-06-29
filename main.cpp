#include"CommonConnectionPool.h"
using namespace std;
int main() {
	clock_t begin = clock();
	ConnectionPool* p = ConnectionPool::getConnectionPool();

	thread t1([]() {
		for (int i = 0; i < 250; i++) {
		/*Connection conn;
		char sql[1024];
		sprintf(sql," insert into user values(NULL, '%d', '%d')",i,i);
		conn.connect("127.0.0.1", 3306, "root", "245330", "javaweb_login");
		conn.update(sql);*/

		ConnectionPool* p = ConnectionPool::getConnectionPool();
		shared_ptr<Connection> conn = p->getConnection();
		char sql[1024];
		sprintf(sql, " insert into user values(NULL, '%d', '%d')", i, i);
		conn->connect("127.0.0.1", 3306, "root", "245330", "javaweb_login");
		conn->update(sql);


		}
		});
	thread t2([]() {
		for (int i = 250; i < 500; i++) {
			/*Connection conn;
			char sql[1024];
			sprintf(sql, " insert into user values(NULL, '%d', '%d')", i, i);
			conn.connect("127.0.0.1", 3306, "root", "245330", "javaweb_login");
			conn.update(sql);*/

			ConnectionPool* p = ConnectionPool::getConnectionPool();
			shared_ptr<Connection> conn = p->getConnection();
			char sql[1024];
			sprintf(sql, " insert into user values(NULL, '%d', '%d')", i, i);
			conn->connect("127.0.0.1", 3306, "root", "245330", "javaweb_login");
			conn->update(sql);


		}
		});
	thread t3([]() {
		for (int i = 500; i < 750; i++) {
		/*	Connection conn;
			char sql[1024];
			sprintf(sql, " insert into user values(NULL, '%d', '%d')", i, i);
			conn.connect("127.0.0.1", 3306, "root", "245330", "javaweb_login");
			conn.update(sql);*/

			ConnectionPool* p = ConnectionPool::getConnectionPool();
			shared_ptr<Connection> conn = p->getConnection();
			char sql[1024];
			sprintf(sql, " insert into user values(NULL, '%d', '%d')", i, i);
			conn->connect("127.0.0.1", 3306, "root", "245330", "javaweb_login");
			conn->update(sql);


		}
		});
	thread t4([]() {
		for (int i = 750; i < 1000; i++) {
		/*	Connection conn;
			char sql[1024];
			sprintf(sql, " insert into user values(NULL, '%d', '%d')", i, i);
			conn.connect("127.0.0.1", 3306, "root", "245330", "javaweb_login");
			conn.update(sql);*/

			ConnectionPool* p = ConnectionPool::getConnectionPool();
			shared_ptr<Connection> conn = p->getConnection();
			char sql[1024];
			sprintf(sql, " insert into user values(NULL, '%d', '%d')", i, i);
			conn->connect("127.0.0.1", 3306, "root", "245330", "javaweb_login");
			conn->update(sql);


		}
		});
	t1.join();
	t2.join();
	t3.join();
	t4.join();

	clock_t end = clock();
	cout << end - begin << "ms" << endl;
	getchar();
}


/*for (int i = 0; i < 5000; i++) {*/
		/*Connection conn;
		char sql[1024];
		sprintf(sql," insert into user values(NULL, '%d', '%d')",i,i);
		conn.connect("127.0.0.1", 3306, "root", "245330", "javaweb_login");
		conn.update(sql);*/

		/*ConnectionPool* p = ConnectionPool::getConnectionPool();
		shared_ptr<Connection> conn = p->getConnection();
		char sql[1024];
		sprintf(sql, " insert into user values(NULL, '%d', '%d')", i, i);
		conn->connect("127.0.0.1", 3306, "root", "245330", "javaweb_login");
		conn->update(sql);*/


		/*}*/