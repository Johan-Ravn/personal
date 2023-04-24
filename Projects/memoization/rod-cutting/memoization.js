let prices = {
    "1": 1,
    "2": 5,
    "3": 8,
    "4": 9,
    "5": 10,
    "6": 17,
    "7": 17,
    "8": 20
};

let prices_size = Object.keys(prices).length;
let length_of_rod_arr = Object.keys(prices).map(Number);

function rod_cutting(rod_length, memo) {
    return rod_cutting_memo(rod_length, 0, memo);
}

function rod_cutting_memo(rod_length, acc_price, memo={}) {
    if (memo[rod_length]) {
        return memo[rod_length];
    } if (rod_length == 0) {
        return acc_price;
    } if (rod_length < 0) {
        return 0;
    }

    let highest_price = 0;
    for (let i = 0; i < prices_size; i++) {
        let best_price = rod_cutting_memo(rod_length - length_of_rod_arr[i], acc_price + Object.values(prices)[i], memo);
        
        if (best_price >= highest_price) {
            highest_price = best_price;
        }
    }
    memo[rod_length] = highest_price;
    return highest_price;
}


function main() {
    for (let i = 1; i < 30; i++) {
        let l = i;
        let memo = new Array(l + 1).fill(undefined);
        console.log(`Optimal price for a rod of ${l}m: ${rod_cutting(l, memo)}`);
    }
}

main();


// | Rod length | Optimal price |
// |------------|---------------|
// | 1          | 1             |
// | 2          | 5             |
// | 3          | 8             |
// | 4          | 10            |
// | 5          | 13            |
// | 6          | 17            |
// | 7          | 18            |
// | 8          | 22            |
// | 9          | 25            |
// | 10         | 30            |
// | 11         | 31            |
// | 12         | 35            |
// | 13         | 38            |
// | 14         | 42            |
// | 15         | 45            |
// | 16         | 50            |
// | 17         | 51            |
// | 18         | 55            |
// | 19         | 58            |
// | 20         | 62            |
// | 21         | 65            |
// | 22         | 70            |
// | 23         | 71            |
// | 24         | 75            |
// | 25         | 78            |
// | 26         | 82            |
// | 27         | 85            |
// | 28         | 90            |
// | 29         | 91            |
// | 30         | 95            |
// | 31         | 98            |
// | 32         | 102           |
// | 33         | 105           |
// | 34         | 110           |
// | 35         | 113           |
// | 36         | 117           |
// | 37         | 120           |
// | 38         | 125           |
// | 39         | 126           |
// | 40         | 130           |
// | 50         | 155           |
// | 60         | 190           |
// | 70         | 225           |
// | 80         | 260           |
// | 90         | 295           |
// | 100        | 330           |
