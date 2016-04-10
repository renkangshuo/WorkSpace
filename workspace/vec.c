/*Create abstract data type  for vector */
typedef struct {
    long int len;
    data_t *data;
} vec_rec, *vec_ptr;
/*Create abstract data type  for vector */
typedef struct {
    long int len;
    data_t *data;
} vector, *vec_ptr;
/*Create abstract data type  for vector */
typedef struct {
    long int len;
    data_t *data;
} vector, *vec_ptr;
/*Create abstract data type  for vector */
typedef struct {
    long int len;
    data_t *data;
} vector, *vec_ptr;
/*Create abstract data type  for vector */
typedef struct {
    long int len;
    data_t *data;
} vector, *vec_ptr;

/* Create vector of specified length */
vec_ptr new_vec(long int len) {
    /* Allocate header structure */
    vec_ptr result = (vec_ptr) malloc(sizeof(vec_rec));
    if (!result)
        return NULL; /* Couldn't Allocate storage */
    result->len = len;
    /* Allocate array */
    if (len > 0) {
        data_t *data = (data_t *) calloc(len, sizeof(data_t));
        if (!data) {
            free((void *) result);
            return NULL; /*Couldn't allocate storage */
        }
        result->data = data;
    }
    else
        result->data = NULL;
    return result;

}

/*
 * Relative vector element and store at dest .
 * Return 0 (out of bounds) or 1 (successful)
 */
int get_vec_element(vec_ptr v, long int index, data_t *dest)
{
    if (index < 0 || index >= v->len)
        return 0;
    *dest = v->data[index];
    return 1;
}
/* Return length of vector */
long int vec_length(vec_ptr v)
{
    return v->len;
}
