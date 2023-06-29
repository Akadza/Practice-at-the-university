#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct UserRatings {
	string userName;
	vector<double> ratings;
};


// Коллаборативная фильтрация для рекомендации фильмов и оценки схожести двух пользователей.
class collFiltering {
public:
	string pathData;
	vector<UserRatings> ratingData;
	bool passRow, passCol;

public:
	// чтение данных csv файла
	void read_csv(void) {
		ifstream dataLine(pathData);
		string line, userName;
		UserRatings user; // данные об одном пользователе
		char delimiter = ',';
		string filmScore;
		double num;

		if (dataLine.is_open())
		{
			if (passRow) getline(dataLine, line); // отбросим ненужную строку
			while (getline(dataLine, line))
			{
				stringstream stream(line);
				getline(stream, user.userName, delimiter);

				while (getline(stream, filmScore, delimiter)) { // добавляем все оценки пользователя
					num = atof(filmScore.c_str());
					user.ratings.push_back(num);
				}
				ratingData.push_back(user); // добавляем пользователя в базу
				user = {};
			}
		}
		else {
			cout << "File wasn't found!" << endl;
			dataLine.close();
			return;
		}
		dataLine.close();
	}


	// выводит общую таблицу рэйтингов
	void print_rating(void) {
		for (int i = 0; i < ratingData.size(); i++)
		{
			cout << ratingData[i].userName << "\t";
			for (int j = 0; j < ratingData[i].ratings.size(); j++)
			{
				cout << ratingData[i].ratings[j] << "   ";
			}
			cout << endl;
		}
	}


	/* проверка на количество поставленных оценок.
	 * Если просмотренных меньше n, возращаем - false
	*/
	bool count_rating_movies(vector<double> moviesRating, int n = 3) {
		int countRatingMovies = 0;
		for (int i = 0; i < moviesRating.size(); i++)
			if (moviesRating[i] != 0.0) countRatingMovies++;
		
		if (countRatingMovies >= n) return true;
		else {
			cout << "User has insufficiently rated movies" << endl;
			return false;
		}
	}

	/* возращает косинусную меру между двумя пользователями
	* VecA - вектор оценок целевого пользователя
	* vecB - вектор сравниваемого пользователя
	*/
	double cos_dist(vector<double> vecA, vector<double> vecB) {
		double cosDist = 0.0;
		double modVecA = 0.0, modVecB = 0.0;
		if (count_rating_movies(vecA, 4))
		{
			// учитываем только те оценки, которые были поставлены
			for (int i = 0; i < vecA.size(); i++) {
				if (vecA[i] != 0.0 && vecB[i] != 0.0) {
					cosDist += vecA[i] * vecB[i];
					modVecA += vecA[i] * vecA[i];
					modVecB += vecB[i] * vecB[i];
				}
			}
			cosDist /= (sqrt(modVecA) * sqrt(modVecB));
		}

		return cosDist;
	}
	
	
	// возращает индекс пользователя по имени
	int find_index(string userName) {
		for (int i = 0; i < ratingData.size(); i++)
			if (userName == ratingData[i].userName) return i;
	}
	
	// возращает имя пользователя по его индексу
	string find_name(int index) {
		return ratingData[index].userName;
	}

	// возращаем имя пользователя, чья оценка наиболее совместима с user'ом на coef и более
	string max_user_compatibility(string corUserName, double coef = 0.8) {
		vector<double> indexCorRating; // все косинусные меры для пользователя
		int indexCorUser = find_index(corUserName);

		for (int i = 0; i < ratingData.size(); i++)
		{
			if (ratingData[i].userName == corUserName) indexCorRating.push_back(-1.0); // учтем одинакового пользователя
			else {
				indexCorRating.push_back(cos_dist(ratingData[indexCorUser].ratings, ratingData[i].ratings));
			}
		}
		
		// вывыдем все косинусные меры
		cout << "\n" << corUserName << "\n";
		for (int i = 0; i < indexCorRating.size(); i++)
		{
			cout << "Coef with << " << ratingData[i].userName << " = " << indexCorRating[i] << endl;
		}

		// найдем максимальную меру
		double maxCoef = indexCorRating[0];
		int indexMax = 0;
		for (int i = 1; i < indexCorRating.size(); i++)
		{
			if (maxCoef < indexCorRating[i] && indexCorRating[i] >= coef)
			{
				maxCoef = indexCorRating[i];
				indexMax = i;
			}
		}
		cout << "\nMax coef = " << maxCoef << endl;
		return find_name(indexMax);
	}


	// выводит коэффициенты рекомендации фильма который пользоватей еще не посмотрел с наибольшей совместимостью
	void make_recommedation(string mainUser) {
		string name = max_user_compatibility(mainUser, 0.9);
		double cosCoef = cos_dist(ratingData[find_index(mainUser)].ratings, ratingData[find_index(name)].ratings);

		cout << "\nRecommendation movies:\n";
		for (int i = 0; i < ratingData[find_index(mainUser)].ratings.size(); i++)
		{
			if (ratingData[find_index(mainUser)].ratings[i] == 0 && ratingData[find_index(name)].ratings[i] != 0) {
				cout << "Movies " << i << " coef = " << ratingData[find_index(name)].ratings[i] * cosCoef << endl;;
			}
		}
	}


	// читаем путь и указываем, нужно ли пропускать строку
	collFiltering(string p_path, bool p_passRow = true) {
		pathData = p_path;
		passRow = p_passRow;
	}
};

int main()
{	
	vector<string> arr;
	collFiltering t("dataFile.csv", false);
	t.read_csv();
	t.print_rating();
	t.count_rating_movies(t.ratingData[0].ratings, 5);
	cout << t.cos_dist(t.ratingData[0].ratings, t.ratingData[1].ratings) << endl;
	cout << t.find_index("Ivan");
	cout << endl;
	t.make_recommedation("Ivan");

	return 0;
}