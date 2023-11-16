#include <iostream>

int max(int a, int b) {
	return (a > b) ? a : b;
}

void moveBack(int arr[], size_t size, size_t start, size_t moveBy) {
	for (size_t i = start; i < size - moveBy; i++) {
		arr[i] = arr[i + moveBy];
	}
}

size_t repeatedChars(int arr[], size_t size, size_t start) {
	size_t count = 0;
	int ref = arr[start];
	while (start < size && arr[start] == ref) {
		count++;
		start++;
	}
	return count;
}

int main() {
	// Вход
	size_t N;
	std::cin >> N;

	int nums[40];
	for (size_t i = 0; i < N; i++) {
		std::cin >> nums[i];
	}

	// Премахване
	/* Логика:
	 * Движим се от ляво на дясно през масива. На всяка позиция поглеждаме колко
	 * пъти последователно се повтаря текущата цифра, тоест ако сме на индекс 0
	 * и имаме стойности "8 8 8 1 2 8", тогава текущата цифра е 8 и тя се повтаря 3 пъти
	 * последователно.
	 *
	 * По условие, ако повтарянето е поне 3 пъти, тогава трябва да "премахнем" цифрите.
	 * Това как става? Еми, с презаписване, изместваме всички цифри назад и намаляваме
	 * използваната дължина на масива.
	 * Тоест, ако имахме масив със стойности { 8, 8, 8, 1, 2, 8, 6 }, и искаме да премахнем първите
	 * три 8ци, първо ги презаписваме с цифрите след тях, масива става { 1, 2, 8, 6, 2, 8, 6 } и сега
	 * последните три цифри са старите стойности, които не искаме да пипаме, затова намаляме и N.
	 *
	 * Обаче, след едно премахване може да се появи второ ново, трябва да върнем индекса назад, но с колко?
	 * Да погледнем примери:
	 * 1 1 1 2 2 2 1
	 * По условие първо премахваме първата 3ка 1ци, после 2ките, тоест в масива остава "1", нямаме месетене назад
	 * 1 1 2 2 2 1
	 * Първо премахваме 2ките, имаме "1 1 1", премахваме тях, остава "". Тоест, трябва да преместим назад с 2 позиции,
	 * за да се озовем в първата от 3те 1ци.
	 * 1 2 2 2 1 1
	 * Аналогично на предходния пример, обаче трябва да се върнем назад с 1 позиция, понеже удряме началото на масива.
	 */
	for (size_t i = 0; i < N; i++) {
		size_t rep = repeatedChars(nums, N, i);
		if (rep >= 3) {
			moveBack(nums, N, i, rep);
			i = max(i - 3, -1);
			N -= rep;
		}
	}

	// Изход
	for (size_t i = 0; i < N; i++) {
		std::cout << nums[i] << " ";
	}
	std::cout << std::endl;
}
