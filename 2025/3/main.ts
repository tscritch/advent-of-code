import { readInput } from "../utils";

const input = await readInput("./3/input.txt");
// const input = `987654321111111\n811111111111119\n234234234234278\n818181911112111`;
// console.log(input);

const lines = input.split("\n");

const joltage_pt1 = lines.reduce((acc: number, line: string) => {
  let left = 0;
  let left_idx = 0;
  // do less than full length cause we can't have a left digit as the last in the line
  for (let i = 0; i < line.length - 1; i++) {
    if (Number(line[i]) > left) {
      left = Number(line[i]);
      left_idx = i;
    }
  }

  let right = 0;
  for (let i = left_idx + 1; i < line.length; i++) {
    if (Number(line[i]) > right) {
      right = Number(line[i]);
    }
  }

  const j = Number(`${left}${right}`);
  console.log(j, left, right);

  acc += j;
  return acc;
}, 0);

const DIGIT_AMOUNT = 12;

const joltage_pt2 = lines.reduce((acc: number, line: string) => {
  let digits: number[] = [];

  let last_idx = 0;
  for (let d = 0; d < DIGIT_AMOUNT; d++) {
    let tmp = 0;
    let len = (d == 0 ? line.length : line.length) - (DIGIT_AMOUNT - 1) + d;
    if (d == DIGIT_AMOUNT - 1) len = line.length;
    for (let i = last_idx; i < len; i++) {
      if (Number(line[i]) > tmp) {
        tmp = Number(line[i]);
        last_idx = i + 1;
      }
    }
    digits[d] = tmp;
  }

  const j = Number(digits.join(""));
  console.log("bank:", j, digits.toString());

  acc += j;
  return acc;
}, 0);

console.log(`Pt 1: ${joltage_pt1}`);
console.log(`Pt 2: ${joltage_pt2}`);
