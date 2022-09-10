/*
INPUTS <number of input lines>
1 2 3 4 5 // numbering for every input line
OUTPUTS <number of output lines>
11 12 13 14 15 // number for every output line
NODES <number of nodes>
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 // list of every node
GATES <number of gates>
<gatetype> <number of inputs> <list of input lines> <output lines>
AND 3 1 2 3 11
OR 2 2 3 6
FANOUT 3 3 7 8 9 // this has 1 input [3] and 3 outputs [7, 8, 9]
// etc etc
*/


// sigh, the blocks need to numbered, don't they

struct Vector{
	int capacity, size;
	int *arr;
};

struct Block{
	int type, num_input, num_output;
	Vector *inputlines, *outputlines;
	Vector *inputLoc, *outputLoc;

	// type
	// 1 AND
	// 2 OR
	// 3 NOT
	// 4 NAND
	// 5 NOR
	// 6 FANOUT
};

struct Node{
	int id;
	int drv_out; // block it is the output of
	vector *drv_in; // blocks it is an input for
};

int vector_init(Vector *v)
{
	int Cap = 5;
	v.capacity = Cap;
	v.size = 0;
	v.arr = (int*)malloc(sizeof(int)*Cap);
	return v.capacity;
}

int vector_insert(Vector *v, int val)
{
		v.size++;
		if(v.size==v.capacity)
		{
			v.capacity = 2*v.capacity;
			v.arr = realloc(v.arr, sizeof(int)*v.capacity);
		}
		v.arr[size-1] = val;
		return v.capacity;
}

int block_init(Block *b)
{
	vector_init(b.inputlines);
	vector_init(b.outputlines);
	vector_init(b.inputLoc);
	vector_init(b.outputLoc);
}

int inputGraph()
{
	FILE *fp;
	char buff[255];
	fp = fopen("input_cir.txt", "r");

	if(!fp)
	{
		printf("Input file not found. Check name\n");
	}

	int input_num, output_num, node_num, gate_num;

	fscanf(fp, "%s", buff);

	if( strcmp(buff, "INPUTS")!=0 )
	{
		printf("Incorrect input format. Input header not found\n");
		return -1;
	}

	fscanf(fp, "%d", &input_num);

	if(input_num<=0)
	{
		printf("Input_num error");
		return -1;
	}

	Vector inputs;
	vector_init(&inputs);

	int in_node;

	for(int i=0; i<input_num; i++)
	{
		fscanf(fp, "%d", &in_node);
		vector_insert(&inputs, in_node);
	}

	fscanf(fp, "%s", buff);

	if( strcmp(buff, "OUTPUTS")!=0 )
	{
		printf("Incorrect input format. Output header not found\n");
		return -1;
	}

	fscanf(fp, "%d", &output_num);

	if(output_num<=0)
	{
		printf("Output_num error");
		return -1;
	}

	Vector outputs;
	vector_init(&outputs);

	int out_node;

	for(int i=0; i<output_num; i++)
	{
		fscanf(fp, "%d", &out_node);
		vector_insert(&outputs, out_node);
	}

}