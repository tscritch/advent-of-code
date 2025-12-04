import { readInput } from "../utils";

const input = await readInput("./4/input.txt");
// const input = await readInput("./4/test.txt");

console.log(input);
const grid = input.split("\n").map((line: string) => line.split(""));

function getAdj(x: number, y: number) {
  const up = y - 1;
  const down = y + 1;
  const left = x - 1;
  const right = x + 1;

  const adj: string[] = [];

  adj.push(grid[up]?.[left]);
  adj.push(grid[up]?.[x]);
  adj.push(grid[up]?.[right]);

  adj.push(grid[y][left]);
  adj.push(grid[y][right]);

  adj.push(grid[down]?.[left]);
  adj.push(grid[down]?.[x]);
  adj.push(grid[down]?.[right]);

  return adj.filter((v) => v !== undefined);
}

function findRolls_pt1() {
  let count = 0;
  for (let l = 0; l < grid.length; l++) {
    for (let i = 0; i < grid[l].length; i++) {
      if (grid[l][i] != "@") continue;
      const adj = getAdj(i, l).filter((v) => v == "@" || v == "x");
      if (adj.length < 4) {
        count++;
        // grid[l][i] = "x";
      }
      // console.log(`x: ${i}, y: ${l}, adj: ${adj}, c: ${count}`);
    }
  }

  // console.log(grid.map((l) => l.join("")).join("\n"));

  return count;
}

function find() {
  let pos: { x: number; y: number }[] = [];
  for (let l = 0; l < grid.length; l++) {
    for (let i = 0; i < grid[l].length; i++) {
      if (grid[l][i] != "@") continue;
      const adj = getAdj(i, l).filter((v) => v == "@");
      if (adj.length < 4) {
        pos.push({ x: i, y: l });
        // grid[l][i] = "x";
      }
      // console.log(`x: ${i}, y: ${l}, adj: ${adj}, c: ${count}`);
    }
  }

  return pos;
}

function remove(pos: { x: number; y: number }[]) {
  pos.forEach((p) => (grid[p.y][p.x] = "."));
}

function findRolls_pt2() {
  let total = 0;
  let more = true;
  let iterations = 0;
  while (true) {
    let pos = find();

    if (pos.length <= 0) break;
    total += pos.length;

    console.log(`Round ${iterations}, found ${pos.length}`);

    remove(pos);

    console.log(grid.map((l) => l.join("")).join("\n"));
    iterations++;
  }

  return total;
}

// console.log("Part 1: ", findRolls_pt1());
console.log("Part 2: ", findRolls_pt2());
