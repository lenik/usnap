void main(int argc, char **argv) {
  printf ("Rename Utitlity	DanSei / 1998.12.11\n");
  if (argc < 3) {
    printf ("Usage:\n\t%s <Old Name> <New Name>\n", argv[0]);
    return;
  }
  if (rename (argv[1], argv[2])) perror ("Error ");
}