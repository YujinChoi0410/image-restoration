void MedianFilter(BYTE **img1, double **img3, int width, int height)
{
	int i, j;

	// 3x3 window �� �ȼ� ������ �����ϱ� ���� 1���� �迭 �����.
	BYTE m[9];

	// 3x3 window �� �ȼ����� 1���� �迭 m�� ����.
	for (j = 1; j < height - 1; j++) {
		for (i = 1; i < width - 1; i++) {
			m[0] = img1[j - 1][i - 1];
			m[1] = img1[j - 1][i];
			m[2] = img1[j - 1][i + 1];
			m[3] = img1[j][i - 1];
			m[4] = img1[j][i];
			m[5] = img1[j][i + 1];
			m[6] = img1[j + 1][i - 1];
			m[7] = img1[j + 1][i];
			m[8] = img1[j + 1][i + 1];

			// BYTE�� �迭 m�� ������������ �����ϴ� �˰���. #include <algorithm> �߰���.
			std::sort(m, m + 9);

			// ������������ ���ĵ� �迭 m���� m[4]�� �߰���.
			img3[j][i] = m[4];
		}
	}
}