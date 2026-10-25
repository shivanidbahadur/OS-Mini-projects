#include <stdio.h>
#define F 3
int cache[F] = {0}, freq[F] = {0}, total = 0;
void lfu_bill(int id, int price) {
    int i, min = 0, found = 0;
    printf("\n→ Scanning Product ID: %d | Price: Rs.%d\n", id, price);
    for(i = 0; i < F; i++)
        if(cache[i] == id) { freq[i]++; found = 1; break; }
    if(!found) {
        for(i = 1; i < F; i++)
            if(freq[i] < freq[min]) min = i;
        printf("  Cache Miss! Evicting Product %d (Frequency: %d)\n", cache[min], freq[min]);
        cache[min] = id;
        freq[min] = 1;
    } else {
        printf("  Cache Hit! Frequency of %d is now: %d\n", id, freq[i]);
    }    total += price;
    printf("  Current Bill Total : Rs.%d\n", total);
    printf("  Cache Status       : ");
    for(i = 0; i < F; i++) printf("[%d:%d] ", cache[i], freq[i]);
    printf("\n------------------------------------\n");
}
int main() {
    int n, i, id, price;
    printf("===== SUPERMARKET LFU BILLING SYSTEM =====\n");
    printf("Enter number of items: ");
    scanf("%d", &n);  
    printf("\nEnter Product ID and Price for %d items:\n", n);
    for(i = 1; i <= n; i++) {
        printf("Item %d → ID Price: ", i);
        scanf("%d %d", &id, &price);
        lfu_bill(id, price);
    }   
    printf("\n============= FINAL BILL =============\n");
    printf("Grand Total Payable : Rs.%d\n", total);
    printf("===== Thank You! Visit Again =====\n");
    return 0;
}
