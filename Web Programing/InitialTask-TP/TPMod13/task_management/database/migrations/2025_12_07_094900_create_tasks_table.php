<?php

use Illuminate\Database\Migrations\Migration;
use Illuminate\Database\Schema\Blueprint;
use Illuminate\Support\Facades\Schema;

return new class extends Migration
{
    public function up(): void
    {
        Schema::create('tasks', function (Blueprint $table) {
            $table->id();                                   // Id (PK, AI)
            $table->string('name');                        // Name (string)
            $table->text('description')->nullable();       // Description (text)
            $table->enum('status', ['pending', 'completed'])
                  ->default('pending');                    // Status enum
            $table->timestamps();                          // created_at & updated_at
        });
    }

    public function down(): void
    {
        $table->dropIfExists('tasks');
    }
};