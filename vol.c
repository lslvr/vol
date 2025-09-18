#include <alsa/asoundlib.h>

int main(int argc, char **argv) {
    long vol;

    snd_mixer_t *handle;
    snd_mixer_elem_t *elem;
    snd_mixer_selem_id_t *sid;
    snd_mixer_open(&handle, 0);
    snd_mixer_attach(handle, "default");
    snd_mixer_selem_register(handle, 0, 0);
    snd_mixer_load(handle);
    snd_mixer_selem_id_malloc(&sid);
    snd_mixer_selem_id_set_index(sid, 0);
    snd_mixer_selem_id_set_name(sid, "Master");
    elem = snd_mixer_find_selem(handle, sid);
    snd_mixer_selem_get_playback_volume(elem, SND_MIXER_SCHN_FRONT_LEFT, &vol);

    if (*argv[1] == '+') vol += 2;
    if (*argv[1] == '-') vol -= 2;

    snd_mixer_selem_set_playback_volume_all(elem, vol);
}
