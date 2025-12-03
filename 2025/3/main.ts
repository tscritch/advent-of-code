import { readInput } from "../utils";

const input = await readInput("./3/input.txt");
// const input = `987654321111111\n811111111111119\n234234234234278\n818181911112111`;
// console.log(input);

const lines = input.split("\n");

const joltage = lines.reduce((acc: number, line: string) => {
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

console.log(`Total: ${joltage}`);
