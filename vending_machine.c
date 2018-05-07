#include <stdio.h>

void vending_machine(void);

int main(void) {

	vending_machine();
	return 0;

}

void vending_machine(void) {
	int i, j, currency;
	int money = 0;
	int coin[4] = { 500, 100, 50, 10 };
	int change[5] = { 0 };
	int price[5] = { 0, 110, 130, 150, 190 };
	char drink[][50] = { "お金を追加投入", "天然水","コーヒー","お茶","青汁" };

	printf("いらっしゃいませ。\n");
	while (1) {



		do {

			do {
				printf("お金を10円単位で投入してください :");
				scanf("%d", &currency);
				if (currency > 0 && currency % 10 == 0) {
					money += currency;
				}
				else {
					printf("使用できない硬貨が投入されました。\n");
				}
				printf("合計金額は%d円です。\n", money);
				if (money < 110) printf("110円未満ですお金を追加投入してください。\n");
			} while (money < 110);

      do {

        for (i = 1; i < 5; i++) {
          printf("%2d : %-15s%5d\n", i, drink[i], price[i]);
          if (i == 4) {
            printf("%2d : %-15s   - \n", 0, drink[0]);
          }
        }
			
				printf("飲み物を選択してください :\n");
				scanf("%d", &i);
				if (i < 0 || i > 4) printf("存在しない商品です。\n");
				if (price[i] > money) {
					printf("お金が%d円足りません。\n", price[i] - money);
					printf("お金を追加投入するか商品を選択しなおしてください。\n");
				}
			} while (i < 0 || i > 4 || price[i] > money);

			if (i == 0) {
				printf("%sしてください。\n", drink[i]);
			}
			else {
				printf("%sが選択されました。\n", drink[i]);
			}
		} while (i == 0);

		change[0] = money - price[i];
		printf("代金は%d円です。　おつりは%d円です。\n", price[i], change[0]);

		printf("続けて購入する 0 / 終了する 1 :");
		scanf("%d", &i);
		if (i != 0) {
			for (j = 1; j < 5; j++) {
				change[j] = change[0] / coin[j - 1];
				change[0] = change[0] % coin[j - 1];
			}
			for (i = 0; i < 4; i++) {
				printf("%4d円", coin[i]);
			}
			printf("\n");
			for (i = 1; i < 5; i++) {
				printf("%4d枚", change[i]);
			}
			printf("\n");
			printf("ありがとうございました。\n");
			scanf("%d", &i);
			break;
		}
		money = change[0];
	}
}