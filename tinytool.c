/* tinytool.c
**
** Copyright 2015, Joshua Henderson
** Copyright 2011, The Android Open Source Project
**
** Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are met:
**     * Redistributions of source code must retain the above copyright
**       notice, this list of conditions and the following disclaimer.
**     * Redistributions in binary form must reproduce the above copyright
**       notice, this list of conditions and the following disclaimer in the
**       documentation and/or other materials provided with the distribution.
**     * Neither the name of The Android Open Source Project nor the names of
**       its contributors may be used to endorse or promote products derived
**       from this software without specific prior written permission.
**
** THIS SOFTWARE IS PROVIDED BY The Android Open Source Project ``AS IS'' AND
** ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
** IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
** ARE DISCLAIMED. IN NO EVENT SHALL The Android Open Source Project BE LIABLE
** FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
** DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
** SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
** CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
** LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
** OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
** DAMAGE.
*/
#include <stdio.h>
#include <string.h>
#include <libgen.h>

extern int tinyplay_main(int argc, char **argv);
extern int tinymix_main(int argc, char **argv);
extern int tinypcminfo_main(int argc, char **argv);
extern int tinycap_main(int argc, char **argv);

int main(int argc, char **argv)
{
   char path[512];
   char* app;

   strcpy(path,argv[0]);

   app = basename(path);

   if (strcmp(app,"tinytool") == 0) {
      printf("tinytool needs to be executed from an app symlink\n");
      return -1;
   }
#ifdef APP_TINYPLAY
   else if (strcmp(app,"tinyplay") == 0)
      return tinyplay_main(argc, argv);
#endif
#ifdef APP_TINYMIX
   else if (strcmp(app,"tinymix") == 0)
      return tinymix_main(argc, argv);
#endif
#ifdef APP_TINYPCMINFO
   else if (strcmp(app,"tinypcminfo") == 0)
      return tinypcminfo_main(argc, argv);
#endif
#ifdef APP_TINYCAP
   else if (strcmp(app,"tinycap") == 0)
      return tinycap_main(argc, argv);
#endif

   printf("unknown app: %s\n",app);

   return -1;
}
