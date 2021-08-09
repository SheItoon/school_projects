/*
** EPITECH PROJECT, 2020
** ftp
** File description:
** ftp
*/

#include <SFML/Graphics.h>
#include <SFML/Network.h>
#include "my.h"
#include <stdlib.h>
#include <stdio.h>
#include "hacker_stuff.h"

void download(sfFtp *server, sfFtpResponse *answer, const char *directory)
{
    sfFtpListingResponse *list;
    size_t list_size = 0;
    const char *item;
    const char *dir;
    char *local;

    answer = sfFtp_changeDirectory(server, directory);
    dir = sfFtpDirectoryResponse_getDirectory
    (sfFtp_getWorkingDirectory(server));
    local = malloc(sizeof(char) * (my_strlen(dir) + 2));
    SETUP_LOCAL;
    list = sfFtp_getDirectoryListing(server, dir);
    list_size = sfFtpListingResponse_getCount(list);
    if (sfFtpResponse_isOk(answer)) {
        for (size_t i = 0; i < list_size; i++) {
            item = sfFtpListingResponse_getName(list, i);           
            sfFtp_download(server, item, local, sfFtpBinary);
        }
        sfFtp_changeDirectory(server, "..");
    }
    sfFtpListingResponse_destroy(list), free(local);
}

static void hacking(sfFtp *server, sfFtpResponse *answer)
{
    answer = sfFtp_changeDirectory(server, "resources");
    if (sfFtpResponse_isOk(answer)) {
        download(server, answer, "musics");
        download(server, answer, "textures");
    }
}

int ftp_init_login(void)
{
    sfFtp *server = sfFtp_create();
    sfFtpResponse *answer;

    answer = sfFtp_connect(server, (sfIpAddress){"161.35.45.2"}, 21, 
    sfSeconds(2));
    answer = sfFtp_login(server, "jajrpg", PASSWORD);
    if (sfFtpResponse_isOk(answer))
        hacking(server, answer);
    else
        return 1;
    sfFtp_disconnect(server), sfFtp_destroy(server);
    sfFtpResponse_destroy(answer);
    return 0;
}
