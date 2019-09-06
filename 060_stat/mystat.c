#include <ctype.h>
#include <grp.h>
#include <limits.h>
#include <pwd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/sysmacros.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

// Step1: accept one filename and print out the first three lines of the output

void print_first_3lines(char * filename, struct stat sb) {
  if (S_ISLNK(sb.st_mode)) {
    char linktarget[256];
    ssize_t len = readlink(filename, linktarget, 256);
    if (len == -1) {
      perror("readlink");
      exit(EXIT_FAILURE);
    }
    linktarget[len] = '\0';
    printf("  File: %s -> %s\n", filename, linktarget);
  }  // Step7: fix the final discrepancy if the file is a symbolic link.
  else {
    printf("  File: %s\n", filename);
  }
  printf(
      "  Size: %-10lu\tBlocks: %-10lu IO Block: %-6lu ", sb.st_size, sb.st_blocks, sb.st_blksize);
  switch (sb.st_mode & S_IFMT) {
    case S_IFBLK:
      printf("block special file\n");
      break;
    case S_IFCHR:
      printf("character special file\n");
      break;
    case S_IFDIR:
      printf("directory\n");
      break;
    case S_IFIFO:
      printf("fifo\n");
      break;
    case S_IFLNK:
      printf("symbolic link\n");
      break;
    case S_IFREG:
      printf("regular file\n");
      break;
    case S_IFSOCK:
      printf("socket\n");
      break;
    default:
      printf("unknown?\n");
      break;
  }
  if (S_ISCHR(sb.st_mode) || S_ISBLK(sb.st_mode)) {
    printf("Device: %lxh/%lud\tInode: %-10lu  Links: %-5lu Device type: %d,%d\n",
           sb.st_dev,
           sb.st_dev,
           sb.st_ino,
           sb.st_nlink,
           major(sb.st_rdev),
           minor(sb.st_rdev));
  }  // Step 6
  else {
    printf("Device: %lxh/%lud\tInode: %-10lu  Links: %-lu\n",
           sb.st_dev,
           sb.st_dev,
           sb.st_ino,
           sb.st_nlink);
  }
}

//Step 2
void print_fourth_line_part1(struct stat sb) {
  printf("Access: (%04o/", sb.st_mode & (~S_IFMT));

  //first of ten characters
  switch (sb.st_mode & S_IFMT) {
    case S_IFBLK:
      printf("b");
      break;
    case S_IFCHR:
      printf("c");
      break;
    case S_IFDIR:
      printf("d");
      break;
    case S_IFIFO:
      printf("p");
      break;
    case S_IFLNK:
      printf("l");
      break;
    case S_IFREG:
      printf("-");
      break;
    case S_IFSOCK:
      printf("s");
      break;
  }
  //second of ten characters
  //whether readable by the owner
  if ((sb.st_mode & S_IRUSR) != 0) {
    printf("r");
  }
  else {
    printf("-");
  }
  // third of ten characters
  //whether writeable by the owner
  if ((sb.st_mode & S_IWUSR) != 0) {
    printf("w");
  }
  else {
    printf("-");
  }

  //fourth of ten characters
  //whether executable by the owner
  if ((sb.st_mode & S_IXUSR) != 0) {
    printf("x");
  }
  else {
    printf("-");
  }

  //fifth of ten characters
  //whether readable by group
  if ((sb.st_mode & S_IRGRP) != 0) {
    printf("r");
  }
  else {
    printf("-");
  }
  //sixth of ten characters
  //whether writeable by group
  if ((sb.st_mode & S_IWGRP) != 0) {
    printf("w");
  }
  else {
    printf("-");
  }
  //seventh of ten characters
  //whether executable by group
  if ((sb.st_mode & S_IXGRP) != 0) {
    printf("x");
  }
  else {
    printf("-");
  }

  //eighth of ten characters
  //whether readable by other
  if ((sb.st_mode & S_IROTH) != 0) {
    printf("r");
  }
  else {
    printf("-");
  }
  //nineth of ten characters
  //whether writeable by other
  if ((sb.st_mode & S_IWOTH) != 0) {
    printf("w");
  }
  else {
    printf("-");
  }
  //tenth of ten characters
  //whether executable by other
  if ((sb.st_mode & S_IXOTH) != 0) {
    printf("x");
  }
  else {
    printf("-");
  }

  printf(")");
}
//Step 3
void print_fourth_line_part2(struct stat sb) {
  printf("  Uid: (%5d/%8s)", sb.st_uid, getpwuid(sb.st_uid)->pw_name);
  printf("   Gid: (%5d/%8s)\n", sb.st_gid, getgrgid(sb.st_gid)->gr_name);
}

//This function is for Step 4
char * time2str(const time_t * when, long ns) {
  char * ans = malloc(128 * sizeof(*ans));
  char temp1[64];
  char temp2[32];
  const struct tm * t = localtime(when);
  strftime(temp1, 512, "%Y-%m-%d %H:%M:%S", t);
  strftime(temp2, 32, "%z", t);
  snprintf(ans, 128, "%s.%09ld %s", temp1, ns, temp2);

  return ans;
}

void print_last_four_lines(struct stat sb) {
  char * atimestr = time2str(&sb.st_atime, sb.st_atim.tv_nsec);
  char * mtimestr = time2str(&sb.st_mtime, sb.st_mtim.tv_nsec);
  char * ctimestr = time2str(&sb.st_ctime, sb.st_ctim.tv_nsec);

  printf("Access: %s\n", atimestr);
  printf("Modify: %s\n", mtimestr);
  printf("Change: %s\n", ctimestr);
  printf(" Birth: -\n");
  free(atimestr);
  free(mtimestr);
  free(ctimestr);
}

int main(int argc, char ** argv) {
  if (argc < 2) {
    fprintf(stderr, "stat: missing operand\nTry 'stat --help' for more information.\n");
    exit(EXIT_FAILURE);
  }
  int i;
  struct stat sb;
  for (i = 1; i < argc; ++i) {
    if (lstat(argv[i], &sb) == -1) {
      perror(argv[i]);
    }
    print_first_3lines(argv[i], sb);
    print_fourth_line_part1(sb);
    print_fourth_line_part2(sb);
    print_last_four_lines(sb);
  }
}
