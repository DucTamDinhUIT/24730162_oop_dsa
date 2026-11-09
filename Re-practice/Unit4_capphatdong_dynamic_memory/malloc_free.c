#include <stdio.h>
#include <stdlib.h> // Bắt buộc để dùng malloc() và free()

int main() {
    int n;
    printf("Nhap so luong phan tu: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("So luong khong hop le!\n");
        return 1;
    }

    // 1. Xin cấp phát n ô nhớ int trên Heap
    int *arr = (int *)malloc(n * sizeof(int));

    // 2. Luôn kiểm tra xem hệ điều hành có cấp phát thành công không
    if (arr == NULL) {
        printf("Khong du bo nho de cap phat!\n");
        return 1;
    }

    // 3. Sử dụng vùng nhớ vừa xin như một mảng bình thường
    printf("Nhap %d so nguyen:\n", n);
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]); // hoặc &*(arr + i)
    }

    printf("\nMang vua nhap: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // 4. Giải phóng vùng nhớ trả lại cho hệ điều hành
    free(arr);

    // 5. Gán về NULL để tránh con trỏ lơ lửng (dangling pointer)
    arr = NULL;

    return 0;
}