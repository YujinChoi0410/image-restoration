void MeanFilter(BYTE **img1, double **img2, int width, int height)
{
	// 3x3 window �����ϱ�. ��ո� ���ϸ� �ǹǷ� ��� ���Ҵ� 1�� ����.
	int window[3][3] = {
		{1, 1, 1},
		{1, 1, 1},
		{1, 1, 1},
	};

	int i, j, m, n, sum;

	// �ֿܰ� �ȼ��� �����ϰ� �����ϱ�
	for (j = 1; j < height - 1; j++) {
		for (i = 1; i < width - 1; i++) {
			sum = 0;

			// 3x3 window �� 9�� �ȼ����� ��� ���ϱ�
			for (m = 0; m < 3; m++) {
				for (n = 0; n < 3; n++) {
					sum += (img1[j - 1 + m][i - 1 + n] * window[m][n]);
				}
			}

			// �ȼ� 9���� ��հ� ���ϱ�
			img2[j][i] = sum / 9.;
		}
	}
}

void CHomework::OnClickedFilter3()
{
	// ���� ���� �����ϱ�
	int width, height, x0, y0;
	BYTE **img1, **img3;
	double **img2;

	// �Է¿��� ���� �б�
	if (!GetCurrentImageInfo(&width, &height, &x0, &y0)) return;

	// BYTE**, double** �ڷ��� �Ҵ��ϱ�
	img1 = cmatrix(height, width);
	img2 = dmatrix(height, width);
	img3 = cmatrix(height, width);

	// ȸ���� ���� �б�
	GetCurrentImageGray(img1);

	// Mean-Filter
	MeanFilter(img1, img2, width, height);

	// ����� ȭ�鿡 ����ϱ� ���� normalize
	DNormalize2D(img2, img3, width, height);

	//ȸ���� ���� ���
	DisplayCimage2D(img3, width, height, x0 + width, y0, true);


	//BYTE**, double** �ڷ��� �Ҵ� �����ϱ�
	free_cmatrix(img1, height, width);
	free_dmatrix(img2, height, width);
	free_cmatrix(img3, height, width);
}
